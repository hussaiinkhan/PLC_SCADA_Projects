#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// PROGRAM PROGRAM0
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,START)
  __DECLARE_VAR(BOOL,STOP)
  __DECLARE_VAR(BOOL,TRAFFICLIGHTS)
  __DECLARE_VAR(BOOL,GREENEW)
  __DECLARE_VAR(BOOL,GREENNS)
  __DECLARE_VAR(BOOL,REDEW)
  __DECLARE_VAR(BOOL,REDNS)
  __DECLARE_VAR(BOOL,YELLOWEW)
  __DECLARE_VAR(BOOL,YELLOWNS)
  STEP __step_list[10];
  UINT __nb_steps;
  ACTION __action_list[7];
  UINT __nb_actions;
  __IEC_BOOL_t __transition_list[12];
  __IEC_BOOL_t __debug_transition_list[12];
  UINT __nb_transitions;
  TIME __lasttick_time;

} PROGRAM0;

void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain);
// Code part
void PROGRAM0_body__(PROGRAM0 *data__);
#endif //__POUS_H
