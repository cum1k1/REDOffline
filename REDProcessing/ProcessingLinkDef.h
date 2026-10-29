#ifdef __CINT__
// general
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link C++ nestedclasses;
// our classes
#pragma link C++ class RED::ProcessingModule+;
//#pragma link C++ class RED::ProcessingManager+;
#pragma link C++ class RED::ClusteringModule+;
#pragma link C++ class RED::CorrectorBallistic+;
#pragma link C++ class RED::CorrectorLowFrequency+;
#pragma link C++ class RED::Generator+;
#pragma link C++ class RED::InputModule+;
#pragma link C++ class RED::OutputModule+;
#pragma link C++ class RED::PulseFinder+;
#pragma link C++ class RED::BaselineParameters+;
#pragma link C++ class RED::REDFileInput+;
#pragma link C++ class RED::RemoveModule+;
//
#endif
