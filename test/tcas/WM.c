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
  cov_label(Positive_RA_Alt_Thresh[Alt_Layer_Value] < 0,1,"WM ABS");
  __retres = Positive_RA_Alt_Thresh[Alt_Layer_Value];
  cov_label(__retres < 0,2,"WM ABS");
  return __retres;
}

int Inhibit_Biased_Climb(void)
{
  int __retres;
  cov_label((Climb_Inhibit != 1) != (Climb_Inhibit == 1),3,"WM ROR");
  cov_label(Climb_Inhibit < 0,4,"WM ABS");
  if (Climb_Inhibit == 1) {
    cov_label(Up_Separation * 100 != Up_Separation + 100,5,"WM AOR");
    cov_label(Up_Separation / 100 != Up_Separation + 100,6,"WM AOR");
    cov_label(Up_Separation - 100 != Up_Separation + 100,7,"WM AOR");
    cov_label(Up_Separation < 0,8,"WM ABS");
    __retres = Up_Separation + 100;
    goto return_label;
  }
  else {
    cov_label(Up_Separation < 0,9,"WM ABS");
    __retres = Up_Separation;
    goto return_label;
  }
  return_label: {
                  cov_label(__retres < 0,10,"WM ABS");
                  return __retres;
                }
}

_Bool Non_Crossing_Biased_Climb(void)
{
  int upward_preferred;
  _Bool result;
  int tmp;
  tmp = Inhibit_Biased_Climb();
  cov_label((tmp < Down_Separation) != (tmp > Down_Separation),11,"WM ROR");
  cov_label((tmp <= Down_Separation) != (tmp > Down_Separation),12,"WM ROR");
  cov_label((tmp >= Down_Separation) != (tmp > Down_Separation),13,"WM ROR");
  cov_label(tmp < 0,14,"WM ABS");
  cov_label(Down_Separation < 0,15,"WM ABS");
  upward_preferred = tmp > Down_Separation;
  cov_label(upward_preferred < 0,16,"WM ABS");
  if (upward_preferred) {
    int tmp_3;
    _Bool tmp_0;
    tmp_0 = Own_Below_Threat();
    cov_label(tmp_0 < 0,17,"WM ABS");
    if (tmp_0) {
      _Bool tmp_1;
      tmp_1 = Own_Below_Threat();
      cov_label(tmp_1 < 0,18,"WM ABS");
      if (tmp_1) {
        int tmp_2;
        tmp_2 = ALIM();
        ;
        cov_label((Down_Separation < tmp_2) != (Down_Separation >= tmp_2),19,
                 "WM ROR");
        cov_label((Down_Separation <= tmp_2) != (Down_Separation >= tmp_2),20,
                 "WM ROR");
        cov_label((Down_Separation > tmp_2) != (Down_Separation >= tmp_2),21,
                 "WM ROR");
        cov_label(Down_Separation < 0,22,"WM ABS");
        cov_label(tmp_2 < 0,23,"WM ABS");
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
    cov_label(tmp_4 < 0,24,"WM ABS");
    if (tmp_4) {
      cov_label((Cur_Vertical_Sep < 300) != (Cur_Vertical_Sep >= 300),25,
               "WM ROR");
      cov_label((Cur_Vertical_Sep <= 300) != (Cur_Vertical_Sep >= 300),26,
               "WM ROR");
      cov_label((Cur_Vertical_Sep > 300) != (Cur_Vertical_Sep >= 300),27,
               "WM ROR");
      cov_label(Cur_Vertical_Sep < 0,28,"WM ABS");
      if (Cur_Vertical_Sep >= 300) {
        int tmp_5;
        tmp_5 = ALIM();
        ;
        cov_label((Up_Separation < tmp_5) != (Up_Separation >= tmp_5),29,
                 "WM ROR");
        cov_label((Up_Separation <= tmp_5) != (Up_Separation >= tmp_5),30,
                 "WM ROR");
        cov_label((Up_Separation > tmp_5) != (Up_Separation >= tmp_5),31,
                 "WM ROR");
        cov_label(Up_Separation < 0,32,"WM ABS");
        cov_label(tmp_5 < 0,33,"WM ABS");
        if (Up_Separation >= tmp_5) tmp_6 = 1; else tmp_6 = 0;
      }
      else tmp_6 = 0;
    }
    else tmp_6 = 0;
    result = (_Bool)(tmp_6 != 0);
  }
  cov_label(result < 0,34,"WM ABS");
  return result;
}

_Bool Non_Crossing_Biased_Descend(void)
{
  int upward_preferred;
  _Bool result;
  int tmp;
  tmp = Inhibit_Biased_Climb();
  cov_label((tmp < Down_Separation) != (tmp > Down_Separation),35,"WM ROR");
  cov_label((tmp <= Down_Separation) != (tmp > Down_Separation),36,"WM ROR");
  cov_label((tmp >= Down_Separation) != (tmp > Down_Separation),37,"WM ROR");
  cov_label(tmp < 0,38,"WM ABS");
  cov_label(Down_Separation < 0,39,"WM ABS");
  upward_preferred = tmp > Down_Separation;
  cov_label(upward_preferred < 0,40,"WM ABS");
  if (upward_preferred) {
    int tmp_2;
    _Bool tmp_0;
    tmp_0 = Own_Below_Threat();
    cov_label(tmp_0 < 0,41,"WM ABS");
    if (tmp_0) {
      cov_label((Cur_Vertical_Sep < 300) != (Cur_Vertical_Sep >= 300),42,
               "WM ROR");
      cov_label((Cur_Vertical_Sep <= 300) != (Cur_Vertical_Sep >= 300),43,
               "WM ROR");
      cov_label((Cur_Vertical_Sep > 300) != (Cur_Vertical_Sep >= 300),44,
               "WM ROR");
      cov_label(Cur_Vertical_Sep < 0,45,"WM ABS");
      if (Cur_Vertical_Sep >= 300) {
        int tmp_1;
        tmp_1 = ALIM();
        ;
        cov_label((Down_Separation < tmp_1) != (Down_Separation >= tmp_1),46,
                 "WM ROR");
        cov_label((Down_Separation <= tmp_1) != (Down_Separation >= tmp_1),47,
                 "WM ROR");
        cov_label((Down_Separation > tmp_1) != (Down_Separation >= tmp_1),48,
                 "WM ROR");
        cov_label(Down_Separation < 0,49,"WM ABS");
        cov_label(tmp_1 < 0,50,"WM ABS");
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
    cov_label(tmp_3 < 0,51,"WM ABS");
    if (tmp_3) {
      _Bool tmp_4;
      tmp_4 = Own_Above_Threat();
      cov_label(tmp_4 < 0,52,"WM ABS");
      if (tmp_4) {
        int tmp_5;
        tmp_5 = ALIM();
        ;
        cov_label((Up_Separation < tmp_5) != (Up_Separation >= tmp_5),53,
                 "WM ROR");
        cov_label((Up_Separation <= tmp_5) != (Up_Separation >= tmp_5),54,
                 "WM ROR");
        cov_label((Up_Separation > tmp_5) != (Up_Separation >= tmp_5),55,
                 "WM ROR");
        cov_label(Up_Separation < 0,56,"WM ABS");
        cov_label(tmp_5 < 0,57,"WM ABS");
        if (Up_Separation >= tmp_5) tmp_6 = 1; else tmp_6 = 0;
      }
      else tmp_6 = 0;
    }
    else tmp_6 = 1;
    result = (_Bool)(tmp_6 != 0);
  }
  cov_label(result < 0,58,"WM ABS");
  return result;
}

_Bool Own_Below_Threat(void)
{
  _Bool __retres;
  cov_label((Own_Tracked_Alt <= Other_Tracked_Alt) != (Own_Tracked_Alt < Other_Tracked_Alt),
           59,"WM ROR");
  cov_label((Own_Tracked_Alt > Other_Tracked_Alt) != (Own_Tracked_Alt < Other_Tracked_Alt),
           60,"WM ROR");
  cov_label((Own_Tracked_Alt >= Other_Tracked_Alt) != (Own_Tracked_Alt < Other_Tracked_Alt),
           61,"WM ROR");
  cov_label(Own_Tracked_Alt < 0,62,"WM ABS");
  cov_label(Other_Tracked_Alt < 0,63,"WM ABS");
  if (Own_Tracked_Alt < Other_Tracked_Alt) {
    __retres = (_Bool)1;
    goto return_label;
  }
  else {
    __retres = (_Bool)0;
    goto return_label;
  }
  return_label: {
                  cov_label(__retres < 0,64,"WM ABS");
                  return __retres;
                }
}

_Bool Own_Above_Threat(void)
{
  _Bool __retres;
  cov_label((Other_Tracked_Alt <= Own_Tracked_Alt) != (Other_Tracked_Alt < Own_Tracked_Alt),
           65,"WM ROR");
  cov_label((Other_Tracked_Alt > Own_Tracked_Alt) != (Other_Tracked_Alt < Own_Tracked_Alt),
           66,"WM ROR");
  cov_label((Other_Tracked_Alt >= Own_Tracked_Alt) != (Other_Tracked_Alt < Own_Tracked_Alt),
           67,"WM ROR");
  cov_label(Other_Tracked_Alt < 0,68,"WM ABS");
  cov_label(Own_Tracked_Alt < 0,69,"WM ABS");
  if (Other_Tracked_Alt < Own_Tracked_Alt) {
    __retres = (_Bool)1;
    goto return_label;
  }
  else {
    __retres = (_Bool)0;
    goto return_label;
  }
  return_label: {
                  cov_label(__retres < 0,70,"WM ABS");
                  return __retres;
                }
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
  cov_label((enabled || (tcas_equipped && intent_not_known || ! tcas_equipped)) != (
           enabled && (tcas_equipped && intent_not_known || ! tcas_equipped)),
           71,"WM COR");
  cov_label(enabled < 0,72,"WM ABS");
  cov_label(((tcas_equipped && intent_not_known) && ! tcas_equipped) != (
           tcas_equipped && intent_not_known || ! tcas_equipped),73,"WM COR");
  cov_label((tcas_equipped || intent_not_known) != (tcas_equipped && intent_not_known),
           74,"WM COR");
  cov_label(tcas_equipped < 0,75,"WM ABS");
  cov_label(intent_not_known < 0,76,"WM ABS");
  cov_label(tcas_equipped < 0,77,"WM ABS");
  if (enabled && (tcas_equipped && intent_not_known || ! tcas_equipped)) {
    int tmp_1;
    _Bool tmp;
    int tmp_4;
    _Bool tmp_2;
    tmp = Non_Crossing_Biased_Climb();
    cov_label(tmp < 0,78,"WM ABS");
    if (tmp) {
      _Bool tmp_0;
      tmp_0 = Own_Below_Threat();
      cov_label(tmp_0 < 0,79,"WM ABS");
      if (tmp_0) tmp_1 = 1; else tmp_1 = 0;
    }
    else tmp_1 = 0;
    need_upward_RA = (_Bool)(tmp_1 != 0);
    tmp_2 = Non_Crossing_Biased_Descend();
    cov_label(tmp_2 < 0,80,"WM ABS");
    if (tmp_2) {
      _Bool tmp_3;
      tmp_3 = Own_Above_Threat();
      cov_label(tmp_3 < 0,81,"WM ABS");
      if (tmp_3) tmp_4 = 1; else tmp_4 = 0;
    }
    else tmp_4 = 0;
    need_downward_RA = (_Bool)(tmp_4 != 0);
    cov_label((need_upward_RA || need_downward_RA) != (need_upward_RA && need_downward_RA),
             82,"WM COR");
    cov_label(need_upward_RA < 0,83,"WM ABS");
    cov_label(need_downward_RA < 0,84,"WM ABS");
    if (need_upward_RA && need_downward_RA) alt_sep = 0;
    else {
      cov_label(need_upward_RA < 0,85,"WM ABS");
      if (need_upward_RA) alt_sep = 1;
      else {
        cov_label(need_downward_RA < 0,86,"WM ABS");
        if (need_downward_RA) alt_sep = 2; else alt_sep = 0;
      }
    }
  }
  cov_label(alt_sep < 0,87,"WM ABS");
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
