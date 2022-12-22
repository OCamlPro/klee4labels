#include "errno.h"
#include "stdarg.h"
#include "stddef.h"
#include "stdio.h"
#include "harness_macros.h"

#ifndef cov_label
#define cov_label(...) do{}while(0)
#endif


int Cur_Vertical_Sep;
_Bool High_Confidence;
_Bool Two_of_Three_Reports_Valid;
int Own_Tracked_Alt;
int Own_Tracked_Alt_Rate;
int Other_Tracked_Alt;
int Alt_Layer_Value;
int Positive_RA_Alt_Thresh[4];
int Up_Separation;
int Down_Separation;
int Other_RAC;
int Other_Capability;
int Climb_Inhibit;
_Bool Own_Below_Threat(void);

_Bool Own_Above_Threat(void);

void initialize(void)
{
  Positive_RA_Alt_Thresh[0] = 400;
  Positive_RA_Alt_Thresh[1] = 500;
  Positive_RA_Alt_Thresh[2] = 640;
  Positive_RA_Alt_Thresh[3] = 740;
  return;
}

int ALIM(void)
{
  int __retres;
  __retres = Positive_RA_Alt_Thresh[Alt_Layer_Value];
  return __retres;
}

int Inhibit_Biased_Climb(void)
{
  int __retres;
  cov_label(Climb_Inhibit == 1,1,"CC");
  cov_label(! (Climb_Inhibit == 1),2,"CC");
  if (Climb_Inhibit == 1) {
    __retres = Up_Separation + 100;
    goto return_label;
  }
  else {
    __retres = Up_Separation;
    goto return_label;
  }
  return_label: return __retres;
}

_Bool Non_Crossing_Biased_Climb(void)
{
  int upward_preferred;
  _Bool result;
  int tmp;
  tmp = Inhibit_Biased_Climb();
  upward_preferred = tmp > Down_Separation;
  cov_label(upward_preferred,3,"CC");
  cov_label(! upward_preferred,4,"CC");
  if (upward_preferred) {
    int tmp_3;
    _Bool tmp_0;
    tmp_0 = Own_Below_Threat();
    cov_label(tmp_0,5,"CC");
    cov_label(! tmp_0,6,"CC");
    if (tmp_0) {
      _Bool tmp_1;
      tmp_1 = Own_Below_Threat();
      cov_label(tmp_1,7,"CC");
      cov_label(! tmp_1,8,"CC");
      if (tmp_1) {
        int tmp_2;
        tmp_2 = ALIM();
        ;
        cov_label(Down_Separation >= tmp_2,9,"CC");
        cov_label(! (Down_Separation >= tmp_2),10,"CC");
        if (Down_Separation >= tmp_2) tmp_3 = 0; else tmp_3 = 1;
      }
      else tmp_3 = 0;
    }
    else tmp_3 = 1;
    result = (_Bool)(tmp_3 != 0);
  }
  else {
    int tmp_6;
    _Bool tmp_4;
    tmp_4 = Own_Above_Threat();
    cov_label(tmp_4,11,"CC");
    cov_label(! tmp_4,12,"CC");
    if (tmp_4) {
      cov_label(Cur_Vertical_Sep >= 300,13,"CC");
      cov_label(! (Cur_Vertical_Sep >= 300),14,"CC");
      if (Cur_Vertical_Sep >= 300) {
        int tmp_5;
        tmp_5 = ALIM();
        ;
        cov_label(Up_Separation >= tmp_5,15,"CC");
        cov_label(! (Up_Separation >= tmp_5),16,"CC");
        if (Up_Separation >= tmp_5) tmp_6 = 1; else tmp_6 = 0;
      }
      else tmp_6 = 0;
    }
    else tmp_6 = 0;
    result = (_Bool)(tmp_6 != 0);
  }
  return result;
}

_Bool Non_Crossing_Biased_Descend(void)
{
  int upward_preferred;
  _Bool result;
  int tmp;
  tmp = Inhibit_Biased_Climb();
  upward_preferred = tmp > Down_Separation;
  cov_label(upward_preferred,17,"CC");
  cov_label(! upward_preferred,18,"CC");
  if (upward_preferred) {
    int tmp_2;
    _Bool tmp_0;
    tmp_0 = Own_Below_Threat();
    cov_label(tmp_0,19,"CC");
    cov_label(! tmp_0,20,"CC");
    if (tmp_0) {
      cov_label(Cur_Vertical_Sep >= 300,21,"CC");
      cov_label(! (Cur_Vertical_Sep >= 300),22,"CC");
      if (Cur_Vertical_Sep >= 300) {
        int tmp_1;
        tmp_1 = ALIM();
        ;
        cov_label(Down_Separation >= tmp_1,23,"CC");
        cov_label(! (Down_Separation >= tmp_1),24,"CC");
        if (Down_Separation >= tmp_1) tmp_2 = 1; else tmp_2 = 0;
      }
      else tmp_2 = 0;
    }
    else tmp_2 = 0;
    result = (_Bool)(tmp_2 != 0);
  }
  else {
    int tmp_6;
    _Bool tmp_3;
    tmp_3 = Own_Above_Threat();
    cov_label(tmp_3,25,"CC");
    cov_label(! tmp_3,26,"CC");
    if (tmp_3) {
      _Bool tmp_4;
      tmp_4 = Own_Above_Threat();
      cov_label(tmp_4,27,"CC");
      cov_label(! tmp_4,28,"CC");
      if (tmp_4) {
        int tmp_5;
        tmp_5 = ALIM();
        ;
        cov_label(Up_Separation >= tmp_5,29,"CC");
        cov_label(! (Up_Separation >= tmp_5),30,"CC");
        if (Up_Separation >= tmp_5) tmp_6 = 1; else tmp_6 = 0;
      }
      else tmp_6 = 0;
    }
    else tmp_6 = 1;
    result = (_Bool)(tmp_6 != 0);
  }
  return result;
}

_Bool Own_Below_Threat(void)
{
  _Bool __retres;
  cov_label(Own_Tracked_Alt < Other_Tracked_Alt,31,"CC");
  cov_label(! (Own_Tracked_Alt < Other_Tracked_Alt),32,"CC");
  if (Own_Tracked_Alt < Other_Tracked_Alt) {
    __retres = (_Bool)1;
    goto return_label;
  }
  else {
    __retres = (_Bool)0;
    goto return_label;
  }
  return_label: return __retres;
}

_Bool Own_Above_Threat(void)
{
  _Bool __retres;
  cov_label(Other_Tracked_Alt < Own_Tracked_Alt,33,"CC");
  cov_label(! (Other_Tracked_Alt < Own_Tracked_Alt),34,"CC");
  if (Other_Tracked_Alt < Own_Tracked_Alt) {
    __retres = (_Bool)1;
    goto return_label;
  }
  else {
    __retres = (_Bool)0;
    goto return_label;
  }
  return_label: return __retres;
}

int alt_sep_test(void)
{
  _Bool enabled;
  _Bool tcas_equipped;
  _Bool intent_not_known;
  _Bool need_upward_RA;
  _Bool need_downward_RA;
  int alt_sep;
  ASSUME(0 <= Alt_Layer_Value);
  ASSUME(Alt_Layer_Value <= 3);
  initialize();
  enabled = (_Bool)(((High_Confidence && Own_Tracked_Alt_Rate <= 600) && 
                     Cur_Vertical_Sep > 600) != 0);
  tcas_equipped = (_Bool)(Other_Capability == 1);
  intent_not_known = (_Bool)((Two_of_Three_Reports_Valid && Other_RAC == 0) != 0);
  alt_sep = 0;
  cov_label(enabled,35,"CC");
  cov_label(! enabled,36,"CC");
  cov_label(tcas_equipped,37,"CC");
  cov_label(! tcas_equipped,38,"CC");
  cov_label(intent_not_known,39,"CC");
  cov_label(! intent_not_known,40,"CC");
  cov_label(tcas_equipped,41,"CC");
  cov_label(! tcas_equipped,42,"CC");
  if (enabled && (tcas_equipped && intent_not_known || ! tcas_equipped)) {
    int tmp_1;
    _Bool tmp;
    int tmp_4;
    _Bool tmp_2;
    tmp = Non_Crossing_Biased_Climb();
    cov_label(tmp,43,"CC");
    cov_label(! tmp,44,"CC");
    if (tmp) {
      _Bool tmp_0;
      tmp_0 = Own_Below_Threat();
      cov_label(tmp_0,45,"CC");
      cov_label(! tmp_0,46,"CC");
      if (tmp_0) tmp_1 = 1; else tmp_1 = 0;
    }
    else tmp_1 = 0;
    need_upward_RA = (_Bool)(tmp_1 != 0);
    tmp_2 = Non_Crossing_Biased_Descend();
    cov_label(tmp_2,47,"CC");
    cov_label(! tmp_2,48,"CC");
    if (tmp_2) {
      _Bool tmp_3;
      tmp_3 = Own_Above_Threat();
      cov_label(tmp_3,49,"CC");
      cov_label(! tmp_3,50,"CC");
      if (tmp_3) tmp_4 = 1; else tmp_4 = 0;
    }
    else tmp_4 = 0;
    need_downward_RA = (_Bool)(tmp_4 != 0);
    cov_label(need_upward_RA,51,"CC");
    cov_label(! need_upward_RA,52,"CC");
    cov_label(need_downward_RA,53,"CC");
    cov_label(! need_downward_RA,54,"CC");
    if (need_upward_RA && need_downward_RA) alt_sep = 0;
    else {
      cov_label(need_upward_RA,55,"CC");
      cov_label(! need_upward_RA,56,"CC");
      if (need_upward_RA) alt_sep = 1;
      else {
        cov_label(need_downward_RA,57,"CC");
        cov_label(! need_downward_RA,58,"CC");
        if (need_downward_RA) alt_sep = 2; else alt_sep = 0;
      }
    }
  }
  return alt_sep;
}


#define _MAX_PTR_ARRAY_LENGTH 1
#define _MAX_CSTRING_LENGTH 20

int main () {

  HARNESS_START;
  _FLAT (Climb_Inhibit, "Climb_Inhibit", int);
  _FLAT (Other_Capability, "Other_Capability", int);
  _FLAT (Other_RAC, "Other_RAC", int);
  _FLAT (Down_Separation, "Down_Separation", int);
  _FLAT (Up_Separation, "Up_Separation", int);
  _FLAT (Positive_RA_Alt_Thresh, "Positive_RA_Alt_Thresh", int[4]);
  _FLAT (Alt_Layer_Value, "Alt_Layer_Value", int);
  _FLAT (Other_Tracked_Alt, "Other_Tracked_Alt", int);
  _FLAT (Own_Tracked_Alt_Rate, "Own_Tracked_Alt_Rate", int);
  _FLAT (Own_Tracked_Alt, "Own_Tracked_Alt", int);
  _FLAT (Two_of_Three_Reports_Valid, "Two_of_Three_Reports_Valid", _Bool);
  _FLAT (High_Confidence, "High_Confidence", _Bool);
  _FLAT (Cur_Vertical_Sep, "Cur_Vertical_Sep", int);
  
  (void) alt_sep_test ();
  HARNESS_END;
  return 0;
}
      
