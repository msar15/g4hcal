// Tell emacs that this is a C++ source
//  -*- C++ -*-.
#ifndef G4DETECTORS_PHG4OUTERHCALDISPLAYACTION_H
#define G4DETECTORS_PHG4OUTERHCALDISPLAYACTION_H

#include <g4main/PHG4DisplayAction.h>

#include <set>
#include <string>  // for string
#include <vector>

class G4LogicalVolume;
class G4VisAttributes;
class G4VPhysicalVolume;

class PHG4OHCalDisplayAction : public PHG4DisplayAction
{
 public:
  PHG4OHCalDisplayAction(const std::string &name);

  ~PHG4OHCalDisplayAction() override;

  void ApplyDisplayAction(G4VPhysicalVolume *physvol) override;
  void SetMyTopVolume(G4VPhysicalVolume *vol) { m_MyTopVolume = vol; }
  void AddScintiVolume(G4LogicalVolume *vol) { m_ScintiLogVolSet.insert(vol); }
  void AddSteelVolume(G4LogicalVolume *vol) { m_SteelVol = vol; }
  void AddChimSteelVolume(G4LogicalVolume *vol) { m_ChimSteelVol = vol; }

 private:
  G4VPhysicalVolume *m_MyTopVolume;
  G4LogicalVolume *m_SteelVol;
  G4LogicalVolume *m_ChimSteelVol;
  std::vector<G4VisAttributes *> m_VisAttVec;
  std::vector<G4VisAttributes *> m_VisAttVec2;
  std::set<G4LogicalVolume *> m_ScintiLogVolSet;
};

#endif  // G4DETECTORS_PHG4OUTERHCALDISPLAYACTION_H
