#include "runinfo.hh"
#include "TQObject.h"
#include "TMacro.h"
#include "TList.h"
#include "TObjString.h"
#include <algorithm>

typedef runinfo::stringmap stringmap;
typedef runinfo::stringvec stringvec;

//utility class to read now-obsolete comment parameter and put into metadata
class CommentReader{
  runinfo* _info;
public:
  CommentReader(runinfo* info) : _info(info) {}
};

runinfo::runinfo(long id) :
  TObject()
{
  Init();
  runid = id;
}

//reset variables that can be read from the raw data
void runinfo::ResetRunStats()
{
  starttime = 0;
  endtime = 0;
  triggers = 0;
  events = 0;
}

void runinfo::Init(bool reset)
{
  runid=-1;
  starttime=0;
  endtime=0;
  triggers=0;
  events=0;

  metadata.clear();
  force_prerun_dialog = false;
  force_postrun_dialog = false;
  channel_metadata.clear();

  if(!reset)
    InitializeParameterList();
}

void runinfo::InitializeParameterList()
{ ; }


int runinfo::LoadSavedInfo(TMacro* mac)
{
  //first, read the macro into a stringstream
  TList* lines = mac->GetListOfLines();
  if(!lines || !lines->GetEntries())
    return 1;
  std::stringstream s;
  TIter next(lines);
  TObjString *obj;
  while ((obj = (TObjString*) next()))
    s<<obj->GetName()<<"\n";
  //if we get here, we should have been successful
  return 0;
}

struct SmapMerge{
  stringmap& mymap;
  SmapMerge(stringmap& amap) : mymap(amap) {}
  void operator()(const std::pair<std::string,std::string>& it)
  { mymap[it.first] = it.second; }
};

void runinfo::MergeMetadata(const runinfo* other, bool overwritedups)
{
  //first do the global metadata
  const stringmap& othermap = other->metadata;
  if(overwritedups)
    std::for_each(othermap.begin(), othermap.end(), SmapMerge(metadata));
  else
    metadata.insert(othermap.begin(), othermap.end());

  //now the channel_metadata
  std::map<int,stringmap>::const_iterator it=other->channel_metadata.begin();
  for( ; it != other->channel_metadata.end(); ++it){
    if(overwritedups)
      std::for_each(it->second.begin(), it->second.end(),
		    SmapMerge(channel_metadata[it->first]));
    else
      channel_metadata[it->first].insert(it->second.begin(), it->second.end());
  }

}

int runinfo::FillDataForRun(runinfo::FILLTIME when)
{
  return 0;
}
//
