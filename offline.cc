#include <iostream>
#include <TApplication.h>
#include <TROOT.h>
#include <TInterpreter.h>
#include <TBufferJSON.h>
#include <cstdlib>
#include <getopt.h> // for getopt_long
#include <iomanip>  // for setw

//#include "REDUtils/SystemOfUnits.h"
#include "REDEvent/Event.hh"
#include "REDProcessing/Generator.hh"
#include "REDProcessing/InputModule.hh"
#include "REDProcessing/OutputModule.hh"
#include "REDProcessing/PulseFinder.hh"
#include "REDProcessing/ClusteringModule.hh"
#include "REDProcessing/RemoveModule.hh"

#include "config.h"

extern int g_techChannels;

int g_techChannels = 0; // a bit mask of channels to skip in clustering

void PrintUsage();

using namespace std;
//using namespace CLHEP;
using namespace RED;


int main(int argc, char **argv)
{

  if (argc == 1) { PrintUsage(); return 0; };

  std::string outfile = "proc-0000-test.root";
  std::string inmodule = "RED::REDFileInput";
  std::string exmodule = "";
  std::string conffile = "";
  std::string crmodule = "";
  int nevents = -1;

  int iFirstFile = 1;
  int iLastFile = argc;
  bool inspect = false;
  bool remove_wf  = true;
  int do_pulses  = 1;
  int do_cluster = 1;
  int process_events = -1;

  const char* short_options = "hvo:n:iwm:I:X:c:C:";

  const struct option long_options[] = {
    { "help",                no_argument,        0,                 'h' },
    { "version",             no_argument,        0,                 'v' },
    { "output",              required_argument,  0,                 'o' },
    { "process-events",      required_argument,  0,                 'n' },
    { "enable-inspector",    no_argument,        0,                 'i' },
    { "enable-waveforms",    no_argument,        0,                 'w' },
    { "disable-pulsefinder", no_argument,        &do_pulses,         0  },
    { "disable-clustering",  no_argument,        &do_cluster,        0  },
    { "channel-mask",        required_argument,  0,                 'm' },
    { "input-module",        required_argument,  0,                 'I' },
    { "extra-module",        required_argument,  0,                 'X' },
    { "config-file",         required_argument,  0,                 'c' },
    { "corrector-module",    required_argument,  0,                 'C' },
    { 0, 0, 0, 0 }
  };

  int option_index = 0;
  int result = 0;

  while (result!=-1) {
    result = getopt_long(argc, argv, short_options, long_options, &option_index);

    if(result == -1) break;

    switch (result) {
      case 'h':
      case '?':
          PrintUsage();
          return 0;
          break;

      case 'v':
          cout << PACKAGE_STRING << "\n"
               << BUILD_CODE << "\n"
               << BUILD_HOST << endl;
          exit(0);

      case 'i':
          inspect = true;
          break;

      case 'w':
          remove_wf = false;
          break;

      case 'o':
          outfile = optarg;
          break;

      case 'n':
          process_events  = atoi(optarg);
          break;

      case 'm':
          g_techChannels = strtol(optarg,0,0);
          break;

      case 'I':
          inmodule = optarg;
          break;

      case 'X':
          exmodule = optarg;
          break;

      case 'c':
          conffile = optarg;
          break;

      case 'C':
          crmodule = optarg;
          break;

      default:
          break;
    }
  }

  iFirstFile = optind;

  TApplication *app = new TApplication("TCanvas",0,0);

  Event *event = new Event();
  ProcessingModuleFactory *f = &ProcessingModuleFactory::GetInstance();
  InputModule *input = dynamic_cast<InputModule*>(f->CreateModule(inmodule.c_str(),"input"));
  if (input==0) {
    cerr << "Bad input module " << inmodule << endl;
    exit(1);
  }
  ProcessingModule *corr = nullptr;
  if (!crmodule.empty())
    corr = f->CreateModule(crmodule.c_str(),"corr");
  PulseFinder *proc = (PulseFinder*)f->CreateModule("RED::PulseFinder","proc");
  ClusteringModule *cl = (ClusteringModule*)f->CreateModule("RED::ClusteringModule","cl");
  ProcessingModule *insp = nullptr;
  if (inspect) insp = f->CreateModule("RED::Inspector","insp");
  RemoveModule *remove = (RemoveModule*)f->CreateModule("RED::RemoveModule","mremove");
  OutputModule *output = (OutputModule*)f->CreateModule("RED::OutputModule","output");
  ProcessingModule *extra = 0;
  if (!exmodule.empty())
    extra = f->CreateModule(exmodule.c_str(),"extra");

  for(int i=iFirstFile; i<iLastFile; i++)
    input->AddFile(argv[i]);
  output->SetOutputName(outfile);

  if (!conffile.empty()) {
    Int_t err = 0;
    gROOT->Macro(conffile.c_str(), &err, false);
    if (err != TInterpreter::kNoError) {
      cerr << "Bad configuration in '" << conffile <<"'"<< endl;
      exit(2);
    }
  }
  {
    TString s;
    cout << "Processing = [\n  ";
    s = TBufferJSON::ConvertToJSON(input,input->IsA());
    s.ReplaceAll("\n","\n  ");
    cout << s << ",\n  ";
    if (corr) {
      s = TBufferJSON::ConvertToJSON(corr,corr->IsA());
      s.ReplaceAll("\n","\n  ");
      cout << s << ",\n  ";
    }
    s = TBufferJSON::ConvertToJSON(proc,proc->IsA());
    s.ReplaceAll("\n","\n  ");
    cout << s <<",\n  ";
    s = TBufferJSON::ConvertToJSON(cl,cl->IsA());
    s.ReplaceAll("\n","\n  ");
    cout << s <<",\n  ";
    if (extra) {
      s = TBufferJSON::ConvertToJSON(extra,extra->IsA());
      s.ReplaceAll("\n","\n  ");
      cout << s << ",\n  ";
    }
    if (inspect) {
      s = TBufferJSON::ConvertToJSON(insp,insp->IsA());
      s.ReplaceAll("\n","\n  ");
      cout << s << ",\n  ";
    }
    if (remove_wf) {
      s = TBufferJSON::ConvertToJSON(remove,remove->IsA());
      s.ReplaceAll("\n","\n  ");
      cout << s << ",\n  ";
    }
    s = TBufferJSON::ConvertToJSON(output,output->IsA());
    s.ReplaceAll("\n","\n  ");
    cout << s;
    cout << "\n]" << endl;
  }

  int objectNumber = 0;

  input->Initialize();
  output->Initialize();

  int anEventCounter = 0;
  bool aTerminateFlag = false;
  do {

    input->BeginOfRun(event);
    output->BeginOfRun(event);

    while (!aTerminateFlag && input->GetStatus() != 5) {

      input->BeginOfRunSegment(event);
      output->BeginOfRunSegment(event);

      while (!aTerminateFlag &&
             input->GetStatus() != 4 && input->GetStatus() != 5) {

        if (input->ProcessEvent(event) == 0) {
          // cout << "event "  <<" "<< event <<" "
          //      << event->fRunNumber <<" "<< event->fEventNumber << endl;
          objectNumber = TProcessID::GetObjectCount();
          if (corr) corr->ProcessEvent(event);
          if (do_pulses  == 1) proc->ProcessEvent(event);
          if (do_cluster == 1) cl->ProcessEvent(event);
          if (extra) extra->ProcessEvent(event);
          if (insp) insp->ProcessEvent(event);
          if (remove_wf) remove->ProcessEvent(event);
          output->ProcessEvent(event);
          anEventCounter++;
          TProcessID::SetObjectCount(objectNumber);
        } else
          std::cout<<"Reading Error " << input->GetStatus() << endl;

        if (process_events > 0 &&
            anEventCounter >= process_events )
          aTerminateFlag = true;
      }

      input->EndOfRunSegment(event);
      output->EndOfRunSegment(event);
      if (input->GetStatus()==ProcessingModule::kEndAll) break;
    }

    input->EndOfRun(event);
    output->EndOfRun(event);
    if (input->GetStatus()==ProcessingModule::kEndAll) break;

  } while ((anEventCounter>0) && !(aTerminateFlag));

  input->ShutDown();
  output->ShutDown();

  // At the end ROOT will delete modules voluntary, we need to do it ourselves to clear from factory
  if (input) f->DestroyModule(input);
  if (corr) f->DestroyModule(corr);
  if (proc) f->DestroyModule(proc);
  if (cl) f->DestroyModule(cl);
  if (extra) f->DestroyModule(extra);
  if (insp) f->DestroyModule(insp);
  if (remove) f->DestroyModule(remove);
  if (output) f->DestroyModule(output);

  return 0;
}

void PrintUsage()
{
  std::cout.setf( std::ios::left );
  std::string prefix = "   ";
  cout << "\nUsage: ./offline [option]... [FILE]...\n"
       << "  Process FILEs through reconstruction, write output to a single file.\n"
       << "  " << BUILD_STRING << "\n"
       << "\nMandatory arguments to long options are mandatory for short options too.\n"
       << prefix << setw(35) << "-h, --help"    << " display this help" << "\n"
       << prefix << setw(35) << "-v, --version"    << " display version information" << "\n"
       << prefix << setw(35) << "-o, --output-file" << " specify output filename" << "\n"
       << prefix << setw(35) << "-n, --event-process" << " quantity of processing events" << "\n"
       << prefix << setw(35) << "-m, --channel-mask" << " set bit mask to skip during clustering" << "\n"
       << prefix << setw(35) << "" << " some channels (veto, trigger etc.)" << "\n"
       << prefix << setw(35) << "-i, --enable-inspector" << " run program with REDInspector" << "\n"
       << prefix << setw(35) << "    --enable-waveforms" << " to write initial waveforms into the output file" << "\n"
       << prefix << setw(35) << "    --disable-pulsefinder" << " do not run pulse finder" << "\n"
       << prefix << setw(35) << "    --disable-clustering" << " do not use the clustering mechanism" << "\n"
       << prefix << setw(35) << "-I  --input-module" << " specify a module to be used to read a file" << "\n"
       << prefix << setw(35) << "-X  --extra-module" << " specify an extra module to be added" << "\n"
       << prefix << setw(35) << "-c  --config-file" << " specify config filename" << "\n"
       << prefix << setw(35) << "-C  --corrector-module" << " specify a module to use for waveform correction" << endl;
}
