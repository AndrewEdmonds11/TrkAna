//
// structs used to record SimParticle information in TTrees.
// All momenta are in units of MeV/c, time in nsec WRT when the proton bunch pulse peak hits the production target,
// positions are in mm WRT the center of the tracker.
// Andy Edmonds (March 2019)
//
#ifndef SimInfo_HH
#define SimInfo_HH
#include "TrkAna/inc/RootVectors.hh"
#include "Offline/MCDataProducts/inc/MCRelationship.hh"
namespace mu2e
{
// general info about the SimParticle which was simulated
  struct SimInfo {
    bool valid = false; // true/false as to whether the data is valid
    int nhits = -1; // number of matched hits in the track generated by this particle
    int nactive = -1; // number of active matched hits in the track generated by this particle
    int rank = -1; // rank of this particle, by # of associated hits
    int pdg = -1; // true PDG code
    int startCode = -1; // creation process code
    int stopCode = -1; // stop process code
    int gen = -1; // generator code
    float time = -1.0;  // Origin time of the SimParticle
    int index; // index into the SimInfo vector
    XYZVectorF mom = XYZVectorF();  // origin momentumof the SimParticle
    XYZVectorF pos = XYZVectorF();  // origin position of the SimParticle
    XYZVectorF endmom = XYZVectorF();  // end momentumof the SimParticle
    XYZVectorF endpos = XYZVectorF();  // end position of the SimParticle
    MCRelationship prirel = MCRelationship(); // relationship to the event primary particles
    MCRelationship trkrel = MCRelationship(); // relationship to the particle that created hits in the track
    void reset() { *this = SimInfo(); }
  };
}
#endif
