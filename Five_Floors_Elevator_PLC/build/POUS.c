void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





inline INT __PROGRAM0_MOVE__INT__INT1(BOOL EN,
  INT IN,
  PROGRAM0 *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE10_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE10_ENO,,__TMP_ENO);
  return __res;
}

inline INT __PROGRAM0_MOVE__INT__INT2(BOOL EN,
  INT IN,
  PROGRAM0 *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE8_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE8_ENO,,__TMP_ENO);
  return __res;
}

inline INT __PROGRAM0_MOVE__INT__INT3(BOOL EN,
  INT IN,
  PROGRAM0 *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE9_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE9_ENO,,__TMP_ENO);
  return __res;
}

inline INT __PROGRAM0_MOVE__INT__INT4(BOOL EN,
  INT IN,
  PROGRAM0 *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE13_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE13_ENO,,__TMP_ENO);
  return __res;
}

inline INT __PROGRAM0_MOVE__INT__INT5(BOOL EN,
  INT IN,
  PROGRAM0 *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE14_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE14_ENO,,__TMP_ENO);
  return __res;
}

inline INT __PROGRAM0_MOVE__INT__INT6(BOOL EN,
  INT IN,
  PROGRAM0 *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE41_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE41_ENO,,__TMP_ENO);
  return __res;
}

void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain) {
  __INIT_VAR(data__->CURRENTFLOOR,0,retain)
  __INIT_VAR(data__->TARGETFLOOR,0,retain)
  __INIT_VAR(data__->ELEVATORUP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ELEVATOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DOOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ELEVATORDOWN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DOOROPEN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FIRSTFLOOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GROUNDFLOOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SECONDFLOOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->THIRDFLOOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FOURTHFLOOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FIFTHFLOOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ELEVATORON,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PULSE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ELEVATOROFF,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FLOORREACHED,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->TON0,retain);
  TON_init__(&data__->TON1,retain);
  CTUD_init__(&data__->CTUD0,retain);
  TP_init__(&data__->TP0,retain);
  TP_init__(&data__->TP1,retain);
  TP_init__(&data__->TP2,retain);
  __INIT_VAR(data__->_TMP_MOVE10_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE10_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE8_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE8_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE9_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE9_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE13_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE13_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE14_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE14_OUT,0,retain)
  __INIT_VAR(data__->_TMP_GT23_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND36_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_LT24_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND38_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NE55_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND58_OUT,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->R_TRIG1,retain);
  __INIT_VAR(data__->_TMP_NE49_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND52_OUT,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->R_TRIG2,retain);
  __INIT_VAR(data__->_TMP_OR77_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE41_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE41_OUT,0,retain)
  __INIT_VAR(data__->_TMP_EQ72_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND69_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_MOVE10_OUT,,__PROGRAM0_MOVE__INT__INT1(
    (BOOL)__GET_VAR(data__->FIRSTFLOOR,),
    (INT)1,
    data__));
  if (__GET_VAR(data__->_TMP_MOVE10_ENO,)) {
    __SET_VAR(data__->,TARGETFLOOR,,__GET_VAR(data__->_TMP_MOVE10_OUT,));
  };
  __SET_VAR(data__->,_TMP_MOVE8_OUT,,__PROGRAM0_MOVE__INT__INT2(
    (BOOL)__GET_VAR(data__->SECONDFLOOR,),
    (INT)2,
    data__));
  if (__GET_VAR(data__->_TMP_MOVE8_ENO,)) {
    __SET_VAR(data__->,TARGETFLOOR,,__GET_VAR(data__->_TMP_MOVE8_OUT,));
  };
  __SET_VAR(data__->,_TMP_MOVE9_OUT,,__PROGRAM0_MOVE__INT__INT3(
    (BOOL)__GET_VAR(data__->THIRDFLOOR,),
    (INT)3,
    data__));
  if (__GET_VAR(data__->_TMP_MOVE9_ENO,)) {
    __SET_VAR(data__->,TARGETFLOOR,,__GET_VAR(data__->_TMP_MOVE9_OUT,));
  };
  __SET_VAR(data__->,_TMP_MOVE13_OUT,,__PROGRAM0_MOVE__INT__INT4(
    (BOOL)__GET_VAR(data__->FOURTHFLOOR,),
    (INT)4,
    data__));
  if (__GET_VAR(data__->_TMP_MOVE13_ENO,)) {
    __SET_VAR(data__->,TARGETFLOOR,,__GET_VAR(data__->_TMP_MOVE13_OUT,));
  };
  __SET_VAR(data__->,_TMP_MOVE14_OUT,,__PROGRAM0_MOVE__INT__INT5(
    (BOOL)__GET_VAR(data__->FIFTHFLOOR,),
    (INT)5,
    data__));
  if (__GET_VAR(data__->_TMP_MOVE14_ENO,)) {
    __SET_VAR(data__->,TARGETFLOOR,,__GET_VAR(data__->_TMP_MOVE14_OUT,));
  };
  __SET_VAR(data__->,_TMP_GT23_OUT,,GT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->CURRENTFLOOR,),
    (INT)__GET_VAR(data__->TARGETFLOOR,)));
  __SET_VAR(data__->,_TMP_AND36_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->ELEVATOR,),
    (BOOL)__GET_VAR(data__->_TMP_GT23_OUT,)));
  __SET_VAR(data__->TON0.,IN,,__GET_VAR(data__->_TMP_AND36_OUT,));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 0, 2, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->,ELEVATORDOWN,,__GET_VAR(data__->TON0.Q,));
  __SET_VAR(data__->,_TMP_LT24_OUT,,LT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->CURRENTFLOOR,),
    (INT)__GET_VAR(data__->TARGETFLOOR,)));
  __SET_VAR(data__->,_TMP_AND38_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->ELEVATOR,),
    (BOOL)__GET_VAR(data__->_TMP_LT24_OUT,)));
  __SET_VAR(data__->TON1.,IN,,__GET_VAR(data__->_TMP_AND38_OUT,));
  __SET_VAR(data__->TON1.,PT,,__time_to_timespec(1, 0, 2, 0, 0, 0));
  TON_body__(&data__->TON1);
  __SET_VAR(data__->,ELEVATORUP,,__GET_VAR(data__->TON1.Q,));
  __SET_VAR(data__->TP0.,IN,,(!(__GET_VAR(data__->PULSE,)) && __GET_VAR(data__->ELEVATOR,)));
  __SET_VAR(data__->TP0.,PT,,__time_to_timespec(1, 0, 1, 0, 0, 0));
  TP_body__(&data__->TP0);
  __SET_VAR(data__->,PULSE,,__GET_VAR(data__->TP0.Q,));
  __SET_VAR(data__->,_TMP_NE55_OUT,,NE__BOOL__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->CURRENTFLOOR,),
    (INT)__GET_VAR(data__->TARGETFLOOR,)));
  __SET_VAR(data__->,_TMP_AND58_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->ELEVATORUP,),
    (BOOL)__GET_VAR(data__->_TMP_NE55_OUT,)));
  __SET_VAR(data__->R_TRIG1.,CLK,,(__GET_VAR(data__->PULSE,) && __GET_VAR(data__->_TMP_AND58_OUT,)));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->,_TMP_NE49_OUT,,NE__BOOL__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->CURRENTFLOOR,),
    (INT)__GET_VAR(data__->TARGETFLOOR,)));
  __SET_VAR(data__->,_TMP_AND52_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->ELEVATORDOWN,),
    (BOOL)__GET_VAR(data__->_TMP_NE49_OUT,)));
  __SET_VAR(data__->R_TRIG2.,CLK,,(__GET_VAR(data__->PULSE,) && __GET_VAR(data__->_TMP_AND52_OUT,)));
  R_TRIG_body__(&data__->R_TRIG2);
  __SET_VAR(data__->CTUD0.,CU,,__GET_VAR(data__->R_TRIG1.Q,));
  __SET_VAR(data__->CTUD0.,CD,,__GET_VAR(data__->R_TRIG2.Q,));
  __SET_VAR(data__->CTUD0.,PV,,__GET_VAR(data__->TARGETFLOOR,));
  CTUD_body__(&data__->CTUD0);
  __SET_VAR(data__->,CURRENTFLOOR,,__GET_VAR(data__->CTUD0.CV,));
  __SET_VAR(data__->,FLOORREACHED,,__GET_VAR(data__->CTUD0.QU,));
  __SET_VAR(data__->,_TMP_OR77_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)(__GET_VAR(data__->FLOORREACHED,) && __GET_VAR(data__->ELEVATOR,)),
    (BOOL)__GET_VAR(data__->DOOR,)));
  __SET_VAR(data__->TP1.,IN,,__GET_VAR(data__->_TMP_OR77_OUT,));
  __SET_VAR(data__->TP1.,PT,,__time_to_timespec(1, 0, 2, 0, 0, 0));
  TP_body__(&data__->TP1);
  __SET_VAR(data__->,DOOROPEN,,__GET_VAR(data__->TP1.Q,));
  __SET_VAR(data__->,FLOORREACHED,,__GET_VAR(data__->CTUD0.QD,));
  __SET_VAR(data__->,_TMP_MOVE41_OUT,,__PROGRAM0_MOVE__INT__INT6(
    (BOOL)__GET_VAR(data__->GROUNDFLOOR,),
    (INT)0,
    data__));
  if (__GET_VAR(data__->_TMP_MOVE41_ENO,)) {
    __SET_VAR(data__->,TARGETFLOOR,,__GET_VAR(data__->_TMP_MOVE41_OUT,));
  };
  __SET_VAR(data__->,_TMP_EQ72_OUT,,EQ__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->CURRENTFLOOR,),
    (INT)__GET_VAR(data__->TARGETFLOOR,)));
  __SET_VAR(data__->,_TMP_AND69_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->ELEVATOR,),
    (BOOL)__GET_VAR(data__->_TMP_EQ72_OUT,)));
  __SET_VAR(data__->TP2.,IN,,__GET_VAR(data__->_TMP_AND69_OUT,));
  __SET_VAR(data__->TP2.,PT,,__time_to_timespec(1, 0, 2, 0, 0, 0));
  TP_body__(&data__->TP2);
  __SET_VAR(data__->,DOOROPEN,,__GET_VAR(data__->TP2.Q,));
  __SET_VAR(data__->,ELEVATOR,,(!(__GET_VAR(data__->ELEVATOROFF,)) && __GET_VAR(data__->ELEVATORON,)));

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





