TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK


PROGRAM program0
  VAR
    Start : BOOL;
    Stop : BOOL;
    TrafficLights : BOOL;
    GreenEW : BOOL;
    GreenNS : BOOL;
    RedEW : BOOL;
    RedNS : BOOL;
    YellowEW : BOOL;
    YellowNS : BOOL;
  END_VAR

  INITIAL_STEP Step0:
    Start(N);
  END_STEP

  TRANSITION FROM Step0 TO Step1
    := Start;
  END_TRANSITION

  STEP Step1:
  END_STEP

  TRANSITION FROM Step1 TO Step3
    := TrafficLights;
  END_TRANSITION

  STEP Step3:
  END_STEP

  TRANSITION FROM Step3 TO Step4
    := True;
  END_TRANSITION

  STEP Step4:
    GreenEW(N);
  END_STEP

  TRANSITION FROM Step4 TO Step5
    := Step4.t>t#5s;
  END_TRANSITION

  STEP Step5:
    YellowEW(N);
  END_STEP

  TRANSITION FROM Step5 TO Step6
    := Step5.t>t#2s;
  END_TRANSITION

  STEP Step6:
    RedEW(N);
  END_STEP

  TRANSITION FROM Step6 TO Step1
    := Step6.t>t#7s;
  END_TRANSITION

  TRANSITION FROM Step3 TO Step7
    := True;
  END_TRANSITION

  STEP Step7:
    RedNS(N);
  END_STEP

  TRANSITION FROM Step7 TO Step8
    := Step7.t>t#7s;
  END_TRANSITION

  STEP Step8:
    GreenNS(N);
  END_STEP

  TRANSITION FROM Step8 TO Step9
    := Step8.t>t#5s;
  END_TRANSITION

  STEP Step9:
    YellowNS(N);
  END_STEP

  TRANSITION FROM Step9 TO Step1
    := Step9.t>t#2s;
  END_TRANSITION

  TRANSITION FROM Step1 TO Step2
    := Stop;
  END_TRANSITION

  STEP Step2:
    RedEW(N);
    RedNS(N);
  END_STEP

  TRANSITION FROM Step2 TO Step1
    := TrafficLights;
  END_TRANSITION

END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
