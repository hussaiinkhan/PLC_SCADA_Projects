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





void BOXSORTING_init__(BOXSORTING *data__, BOOL retain) {
  __INIT_VAR(data__->START,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STOP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PULSE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MAINCONVEYER,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSOR1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSOR2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSOR3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LEFTCONVEYER,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RIGHTCONVEYER,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MIDDLECONVEYER,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SMALLBOXES,0,retain)
  __INIT_VAR(data__->TOTALBOXES,0,retain)
  __INIT_VAR(data__->SMALLBOXESALARM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MEDIUMBOXESALARM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LARGEBOXESALARM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MEDIUMBOXES,0,retain)
  __INIT_VAR(data__->LARGEBOXES,0,retain)
  TON_init__(&data__->TON0,retain);
  TON_init__(&data__->TON1,retain);
  TON_init__(&data__->TON2,retain);
  CTU_init__(&data__->CTU0,retain);
  CTU_init__(&data__->CTU1,retain);
  CTU_init__(&data__->CTU2,retain);
  TP_init__(&data__->TP0,retain);
  TP_init__(&data__->TP1,retain);
  TP_init__(&data__->TP2,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
  R_TRIG_init__(&data__->R_TRIG2,retain);
  R_TRIG_init__(&data__->R_TRIG3,retain);
  __INIT_VAR(data__->_TMP_ADD70_OUT,0,retain)
}

// Code part
void BOXSORTING_body__(BOXSORTING *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,MAINCONVEYER,,(!(__GET_VAR(data__->STOP,)) && (__GET_VAR(data__->MAINCONVEYER,) || __GET_VAR(data__->START,))));
  __SET_VAR(data__->TON0.,IN,,(!(__GET_VAR(data__->PULSE,)) && __GET_VAR(data__->MAINCONVEYER,)));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 0, 5, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->,SENSOR1,,__GET_VAR(data__->TON0.Q,));
  __SET_VAR(data__->TON1.,IN,,(!(__GET_VAR(data__->PULSE,)) && __GET_VAR(data__->MAINCONVEYER,)));
  __SET_VAR(data__->TON1.,PT,,__time_to_timespec(1, 0, 12, 0, 0, 0));
  TON_body__(&data__->TON1);
  __SET_VAR(data__->,SENSOR2,,__GET_VAR(data__->TON1.Q,));
  __SET_VAR(data__->TON2.,IN,,(!(__GET_VAR(data__->PULSE,)) && __GET_VAR(data__->MAINCONVEYER,)));
  __SET_VAR(data__->TON2.,PT,,__time_to_timespec(1, 0, 17, 0, 0, 0));
  TON_body__(&data__->TON2);
  __SET_VAR(data__->,SENSOR3,,__GET_VAR(data__->TON2.Q,));
  __SET_VAR(data__->R_TRIG1.,CLK,,((!(__GET_VAR(data__->SENSOR3,)) && !(__GET_VAR(data__->SENSOR2,))) && __GET_VAR(data__->SENSOR1,)));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->CTU0.,CU,,__GET_VAR(data__->R_TRIG1.Q,));
  __SET_VAR(data__->CTU0.,R,,__GET_VAR(data__->RESET,));
  __SET_VAR(data__->CTU0.,PV,,15);
  CTU_body__(&data__->CTU0);
  __SET_VAR(data__->,SMALLBOXES,,__GET_VAR(data__->CTU0.CV,));
  __SET_VAR(data__->,SMALLBOXESALARM,,__GET_VAR(data__->CTU0.Q,));
  __SET_VAR(data__->R_TRIG2.,CLK,,((!(__GET_VAR(data__->SENSOR3,)) && __GET_VAR(data__->SENSOR2,)) && __GET_VAR(data__->SENSOR1,)));
  R_TRIG_body__(&data__->R_TRIG2);
  __SET_VAR(data__->CTU1.,CU,,__GET_VAR(data__->R_TRIG2.Q,));
  __SET_VAR(data__->CTU1.,R,,__GET_VAR(data__->RESET,));
  __SET_VAR(data__->CTU1.,PV,,15);
  CTU_body__(&data__->CTU1);
  __SET_VAR(data__->,MEDIUMBOXES,,__GET_VAR(data__->CTU1.CV,));
  __SET_VAR(data__->,MEDIUMBOXESALARM,,__GET_VAR(data__->CTU1.Q,));
  __SET_VAR(data__->R_TRIG3.,CLK,,((__GET_VAR(data__->SENSOR3,) && __GET_VAR(data__->SENSOR2,)) && __GET_VAR(data__->SENSOR1,)));
  R_TRIG_body__(&data__->R_TRIG3);
  __SET_VAR(data__->CTU2.,CU,,__GET_VAR(data__->R_TRIG3.Q,));
  __SET_VAR(data__->CTU2.,R,,__GET_VAR(data__->RESET,));
  __SET_VAR(data__->CTU2.,PV,,15);
  CTU_body__(&data__->CTU2);
  __SET_VAR(data__->,LARGEBOXES,,__GET_VAR(data__->CTU2.CV,));
  __SET_VAR(data__->,LARGEBOXESALARM,,__GET_VAR(data__->CTU2.Q,));
  __SET_VAR(data__->TP0.,IN,,((!(__GET_VAR(data__->SENSOR3,)) && !(__GET_VAR(data__->SENSOR2,))) && __GET_VAR(data__->SENSOR1,)));
  __SET_VAR(data__->TP0.,PT,,__time_to_timespec(1, 0, 3, 0, 0, 0));
  TP_body__(&data__->TP0);
  __SET_VAR(data__->,LEFTCONVEYER,,__GET_VAR(data__->TP0.Q,));
  __SET_VAR(data__->TP1.,IN,,((!(__GET_VAR(data__->SENSOR3,)) && __GET_VAR(data__->SENSOR2,)) && __GET_VAR(data__->SENSOR1,)));
  __SET_VAR(data__->TP1.,PT,,__time_to_timespec(1, 0, 3, 0, 0, 0));
  TP_body__(&data__->TP1);
  __SET_VAR(data__->,MIDDLECONVEYER,,__GET_VAR(data__->TP1.Q,));
  __SET_VAR(data__->TP2.,IN,,((__GET_VAR(data__->SENSOR3,) && __GET_VAR(data__->SENSOR2,)) && __GET_VAR(data__->SENSOR1,)));
  __SET_VAR(data__->TP2.,PT,,__time_to_timespec(1, 0, 3, 0, 0, 0));
  TP_body__(&data__->TP2);
  __SET_VAR(data__->,RIGHTCONVEYER,,__GET_VAR(data__->TP2.Q,));
  __SET_VAR(data__->,PULSE,,__GET_VAR(data__->TON0.Q,));
  __SET_VAR(data__->,PULSE,,__GET_VAR(data__->TON1.Q,));
  __SET_VAR(data__->,PULSE,,__GET_VAR(data__->TON2.Q,));
  __SET_VAR(data__->,_TMP_ADD70_OUT,,ADD__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)3,
    (INT)__GET_VAR(data__->SMALLBOXES,),
    (INT)__GET_VAR(data__->MEDIUMBOXES,),
    (INT)__GET_VAR(data__->LARGEBOXES,)));
  __SET_VAR(data__->,TOTALBOXES,,__GET_VAR(data__->_TMP_ADD70_OUT,));

  goto __end;

__end:
  return;
} // BOXSORTING_body__() 





