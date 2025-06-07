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





void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain) {
  __INIT_VAR(data__->START,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STOP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRAFFICLIGHTS,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GREENEW,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GREENNS,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REDEW,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REDNS,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->YELLOWEW,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->YELLOWNS,__BOOL_LITERAL(FALSE),retain)
  UINT i;
  data__->__nb_steps = 10;
  static const STEP temp_step = {{0, 0}, 0, {0, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  data__->__nb_actions = 7;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 12;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define STEP0 __step_list[0]
#define __SFC_STEP0 0
#define STEP1 __step_list[1]
#define __SFC_STEP1 1
#define STEP3 __step_list[2]
#define __SFC_STEP3 2
#define STEP4 __step_list[3]
#define __SFC_STEP4 3
#define STEP5 __step_list[4]
#define __SFC_STEP5 4
#define STEP6 __step_list[5]
#define __SFC_STEP6 5
#define STEP7 __step_list[6]
#define __SFC_STEP7 6
#define STEP8 __step_list[7]
#define __SFC_STEP8 7
#define STEP9 __step_list[8]
#define __SFC_STEP9 8
#define STEP2 __step_list[9]
#define __SFC_STEP2 9

// Actions definitions
#define __SFC_START 0
#define __SFC_GREENEW 1
#define __SFC_YELLOWEW 2
#define __SFC_REDEW 3
#define __SFC_REDNS 4
#define __SFC_GREENNS 5
#define __SFC_YELLOWNS 6

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  INT i;
  TIME elapsed_time, current_time;

  // Calculate elapsed_time
  current_time = __CURRENT_TIME;
  elapsed_time = __time_sub(current_time, data__->__lasttick_time);
  data__->__lasttick_time = current_time;
  // Transitions initialization
  if (__DEBUG) {
    for (i = 0; i < data__->__nb_transitions; i++) {
      data__->__transition_list[i] = data__->__debug_transition_list[i];
    }
  }
  // Steps initialization
  for (i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i].prev_state = __GET_VAR(data__->__step_list[i].X);
    if (__GET_VAR(data__->__step_list[i].X)) {
      data__->__step_list[i].T.value = __time_add(data__->__step_list[i].T.value, elapsed_time);
    }
  }
  // Actions initialization
  for (i = 0; i < data__->__nb_actions; i++) {
    __SET_VAR(data__->,__action_list[i].state,,0);
    data__->__action_list[i].set = 0;
    data__->__action_list[i].reset = 0;
    if (__time_cmp(data__->__action_list[i].set_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) > 0) {
      data__->__action_list[i].set_remaining_time = __time_sub(data__->__action_list[i].set_remaining_time, elapsed_time);
      if (__time_cmp(data__->__action_list[i].set_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) <= 0) {
        data__->__action_list[i].set_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
        data__->__action_list[i].set = 1;
      }
    }
    if (__time_cmp(data__->__action_list[i].reset_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) > 0) {
      data__->__action_list[i].reset_remaining_time = __time_sub(data__->__action_list[i].reset_remaining_time, elapsed_time);
      if (__time_cmp(data__->__action_list[i].reset_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) <= 0) {
        data__->__action_list[i].reset_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
        data__->__action_list[i].reset = 1;
      }
    }
  }

  // Transitions fire test
  if (__GET_VAR(data__->STEP0.X)) {
    __SET_VAR(data__->,__transition_list[0],,__GET_VAR(data__->START,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->START,));
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->STEP1.X)) {
    __SET_VAR(data__->,__transition_list[1],,__GET_VAR(data__->TRAFFICLIGHTS,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->__transition_list[1]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->TRAFFICLIGHTS,));
    }
    __SET_VAR(data__->,__transition_list[1],,0);
  }
  if (__GET_VAR(data__->STEP3.X)) {
    __SET_VAR(data__->,__transition_list[2],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->__transition_list[2]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[2],,0);
  }
  if (__GET_VAR(data__->STEP4.X)) {
    __SET_VAR(data__->,__transition_list[3],,GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->STEP4.T,), __time_to_timespec(1, 0, 5, 0, 0, 0)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->__transition_list[3]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->STEP4.T,), __time_to_timespec(1, 0, 5, 0, 0, 0)));
    }
    __SET_VAR(data__->,__transition_list[3],,0);
  }
  if (__GET_VAR(data__->STEP5.X)) {
    __SET_VAR(data__->,__transition_list[4],,GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->STEP5.T,), __time_to_timespec(1, 0, 2, 0, 0, 0)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->__transition_list[4]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->STEP5.T,), __time_to_timespec(1, 0, 2, 0, 0, 0)));
    }
    __SET_VAR(data__->,__transition_list[4],,0);
  }
  if (__GET_VAR(data__->STEP6.X)) {
    __SET_VAR(data__->,__transition_list[5],,GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->STEP6.T,), __time_to_timespec(1, 0, 7, 0, 0, 0)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->__transition_list[5]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->STEP6.T,), __time_to_timespec(1, 0, 7, 0, 0, 0)));
    }
    __SET_VAR(data__->,__transition_list[5],,0);
  }
  if (__GET_VAR(data__->STEP3.X)) {
    __SET_VAR(data__->,__transition_list[6],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->__transition_list[6]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[6],,0);
  }
  if (__GET_VAR(data__->STEP7.X)) {
    __SET_VAR(data__->,__transition_list[7],,GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->STEP7.T,), __time_to_timespec(1, 0, 7, 0, 0, 0)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->__transition_list[7]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->STEP7.T,), __time_to_timespec(1, 0, 7, 0, 0, 0)));
    }
    __SET_VAR(data__->,__transition_list[7],,0);
  }
  if (__GET_VAR(data__->STEP8.X)) {
    __SET_VAR(data__->,__transition_list[8],,GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->STEP8.T,), __time_to_timespec(1, 0, 5, 0, 0, 0)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->__transition_list[8]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->STEP8.T,), __time_to_timespec(1, 0, 5, 0, 0, 0)));
    }
    __SET_VAR(data__->,__transition_list[8],,0);
  }
  if (__GET_VAR(data__->STEP9.X)) {
    __SET_VAR(data__->,__transition_list[9],,GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->STEP9.T,), __time_to_timespec(1, 0, 2, 0, 0, 0)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->__transition_list[9]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->STEP9.T,), __time_to_timespec(1, 0, 2, 0, 0, 0)));
    }
    __SET_VAR(data__->,__transition_list[9],,0);
  }
  if (__GET_VAR(data__->STEP1.X)) {
    __SET_VAR(data__->,__transition_list[10],,__GET_VAR(data__->STOP,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->__transition_list[10]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->STOP,));
    }
    __SET_VAR(data__->,__transition_list[10],,0);
  }
  if (__GET_VAR(data__->STEP2.X)) {
    __SET_VAR(data__->,__transition_list[11],,__GET_VAR(data__->TRAFFICLIGHTS,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->__transition_list[11]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->TRAFFICLIGHTS,));
    }
    __SET_VAR(data__->,__transition_list[11],,0);
  }

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,STEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,STEP1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,STEP3.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,STEP4.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,STEP5.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,STEP6.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,STEP3.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,STEP7.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,STEP8.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,STEP9.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,STEP1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,STEP2.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,STEP1.X,,1);
    data__->STEP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,STEP3.X,,1);
    data__->STEP3.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,STEP4.X,,1);
    data__->STEP4.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,STEP5.X,,1);
    data__->STEP5.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,STEP6.X,,1);
    data__->STEP6.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,STEP1.X,,1);
    data__->STEP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,STEP7.X,,1);
    data__->STEP7.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,STEP8.X,,1);
    data__->STEP8.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,STEP9.X,,1);
    data__->STEP9.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,STEP1.X,,1);
    data__->STEP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,STEP2.X,,1);
    data__->STEP2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,STEP1.X,,1);
    data__->STEP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // STEP0 action associations
  {
    char active = __GET_VAR(data__->STEP0.X);
    char activated = active && !data__->STEP0.prev_state;
    char desactivated = !active && data__->STEP0.prev_state;

    if (active)       {__SET_VAR(data__->,START,,1);};
    if (desactivated) {__SET_VAR(data__->,START,,0);};

  }

  // STEP4 action associations
  {
    char active = __GET_VAR(data__->STEP4.X);
    char activated = active && !data__->STEP4.prev_state;
    char desactivated = !active && data__->STEP4.prev_state;

    if (active)       {__SET_VAR(data__->,GREENEW,,1);};
    if (desactivated) {__SET_VAR(data__->,GREENEW,,0);};

  }

  // STEP5 action associations
  {
    char active = __GET_VAR(data__->STEP5.X);
    char activated = active && !data__->STEP5.prev_state;
    char desactivated = !active && data__->STEP5.prev_state;

    if (active)       {__SET_VAR(data__->,YELLOWEW,,1);};
    if (desactivated) {__SET_VAR(data__->,YELLOWEW,,0);};

  }

  // STEP6 action associations
  {
    char active = __GET_VAR(data__->STEP6.X);
    char activated = active && !data__->STEP6.prev_state;
    char desactivated = !active && data__->STEP6.prev_state;

    if (active)       {__SET_VAR(data__->,REDEW,,1);};
    if (desactivated) {__SET_VAR(data__->,REDEW,,0);};

  }

  // STEP7 action associations
  {
    char active = __GET_VAR(data__->STEP7.X);
    char activated = active && !data__->STEP7.prev_state;
    char desactivated = !active && data__->STEP7.prev_state;

    if (active)       {__SET_VAR(data__->,REDNS,,1);};
    if (desactivated) {__SET_VAR(data__->,REDNS,,0);};

  }

  // STEP8 action associations
  {
    char active = __GET_VAR(data__->STEP8.X);
    char activated = active && !data__->STEP8.prev_state;
    char desactivated = !active && data__->STEP8.prev_state;

    if (active)       {__SET_VAR(data__->,GREENNS,,1);};
    if (desactivated) {__SET_VAR(data__->,GREENNS,,0);};

  }

  // STEP9 action associations
  {
    char active = __GET_VAR(data__->STEP9.X);
    char activated = active && !data__->STEP9.prev_state;
    char desactivated = !active && data__->STEP9.prev_state;

    if (active)       {__SET_VAR(data__->,YELLOWNS,,1);};
    if (desactivated) {__SET_VAR(data__->,YELLOWNS,,0);};

  }

  // STEP2 action associations
  {
    char active = __GET_VAR(data__->STEP2.X);
    char activated = active && !data__->STEP2.prev_state;
    char desactivated = !active && data__->STEP2.prev_state;

    if (active)       {__SET_VAR(data__->,REDEW,,1);};
    if (desactivated) {__SET_VAR(data__->,REDEW,,0);};

    if (active)       {__SET_VAR(data__->,REDNS,,1);};
    if (desactivated) {__SET_VAR(data__->,REDNS,,0);};

  }


  // Actions state evaluation
  for (i = 0; i < data__->__nb_actions; i++) {
    if (data__->__action_list[i].set) {
      data__->__action_list[i].set_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
      data__->__action_list[i].stored = 1;
    }
    if (data__->__action_list[i].reset) {
      data__->__action_list[i].reset_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
      data__->__action_list[i].stored = 0;
    }
    __SET_VAR(data__->,__action_list[i].state,,__GET_VAR(data__->__action_list[i].state) | data__->__action_list[i].stored);
  }

  // Actions execution
  if (data__->__action_list[__SFC_START].reset) {
    __SET_VAR(data__->,START,,0);
  }
  else if (data__->__action_list[__SFC_START].set) {
    __SET_VAR(data__->,START,,1);
  }
  if (data__->__action_list[__SFC_GREENEW].reset) {
    __SET_VAR(data__->,GREENEW,,0);
  }
  else if (data__->__action_list[__SFC_GREENEW].set) {
    __SET_VAR(data__->,GREENEW,,1);
  }
  if (data__->__action_list[__SFC_YELLOWEW].reset) {
    __SET_VAR(data__->,YELLOWEW,,0);
  }
  else if (data__->__action_list[__SFC_YELLOWEW].set) {
    __SET_VAR(data__->,YELLOWEW,,1);
  }
  if (data__->__action_list[__SFC_REDEW].reset) {
    __SET_VAR(data__->,REDEW,,0);
  }
  else if (data__->__action_list[__SFC_REDEW].set) {
    __SET_VAR(data__->,REDEW,,1);
  }
  if (data__->__action_list[__SFC_REDNS].reset) {
    __SET_VAR(data__->,REDNS,,0);
  }
  else if (data__->__action_list[__SFC_REDNS].set) {
    __SET_VAR(data__->,REDNS,,1);
  }
  if (data__->__action_list[__SFC_GREENNS].reset) {
    __SET_VAR(data__->,GREENNS,,0);
  }
  else if (data__->__action_list[__SFC_GREENNS].set) {
    __SET_VAR(data__->,GREENNS,,1);
  }
  if (data__->__action_list[__SFC_YELLOWNS].reset) {
    __SET_VAR(data__->,YELLOWNS,,0);
  }
  else if (data__->__action_list[__SFC_YELLOWNS].set) {
    __SET_VAR(data__->,YELLOWNS,,1);
  }


  goto __end;

__end:
  return;
} // PROGRAM0_body__() 

// Steps undefinitions
#undef STEP0
#undef __SFC_STEP0
#undef STEP1
#undef __SFC_STEP1
#undef STEP3
#undef __SFC_STEP3
#undef STEP4
#undef __SFC_STEP4
#undef STEP5
#undef __SFC_STEP5
#undef STEP6
#undef __SFC_STEP6
#undef STEP7
#undef __SFC_STEP7
#undef STEP8
#undef __SFC_STEP8
#undef STEP9
#undef __SFC_STEP9
#undef STEP2
#undef __SFC_STEP2

// Actions undefinitions
#undef __SFC_START
#undef __SFC_GREENEW
#undef __SFC_YELLOWEW
#undef __SFC_REDEW
#undef __SFC_REDNS
#undef __SFC_GREENNS
#undef __SFC_YELLOWNS





