PROGRAM program0
  VAR
    CurrentFloor : INT;
    TargetFloor : INT;
    ElevatorUp : BOOL;
    Elevator : BOOL;
    Door : BOOL;
    ElevatorDown : BOOL;
    DoorOpen : BOOL;
    FirstFloor : BOOL;
    GroundFloor : BOOL;
    SecondFloor : BOOL;
    ThirdFloor : BOOL;
    FourthFloor : BOOL;
    FifthFloor : BOOL;
    ElevatorOn : BOOL;
    Pulse : BOOL;
    ElevatorOff : BOOL;
    FloorReached : BOOL;
    TON0 : TON;
    TON1 : TON;
    CTUD0 : CTUD;
    TP0 : TP;
    TP1 : TP;
    TP2 : TP;
    _TMP_MOVE10_ENO : BOOL;
    _TMP_MOVE10_OUT : INT;
    _TMP_MOVE8_ENO : BOOL;
    _TMP_MOVE8_OUT : INT;
    _TMP_MOVE9_ENO : BOOL;
    _TMP_MOVE9_OUT : INT;
    _TMP_MOVE13_ENO : BOOL;
    _TMP_MOVE13_OUT : INT;
    _TMP_MOVE14_ENO : BOOL;
    _TMP_MOVE14_OUT : INT;
    _TMP_GT23_OUT : BOOL;
    _TMP_AND36_OUT : BOOL;
    _TMP_LT24_OUT : BOOL;
    _TMP_AND38_OUT : BOOL;
    _TMP_NE55_OUT : BOOL;
    _TMP_AND58_OUT : BOOL;
    R_TRIG1 : R_TRIG;
    _TMP_NE49_OUT : BOOL;
    _TMP_AND52_OUT : BOOL;
    R_TRIG2 : R_TRIG;
    _TMP_OR77_OUT : BOOL;
    _TMP_MOVE41_ENO : BOOL;
    _TMP_MOVE41_OUT : INT;
    _TMP_EQ72_OUT : BOOL;
    _TMP_AND69_OUT : BOOL;
  END_VAR

  _TMP_MOVE10_OUT := MOVE(EN := FirstFloor, IN := 1, ENO => _TMP_MOVE10_ENO);
  IF _TMP_MOVE10_ENO THEN
      TargetFloor := _TMP_MOVE10_OUT;
  END_IF;
  _TMP_MOVE8_OUT := MOVE(EN := SecondFloor, IN := 2, ENO => _TMP_MOVE8_ENO);
  IF _TMP_MOVE8_ENO THEN
      TargetFloor := _TMP_MOVE8_OUT;
  END_IF;
  _TMP_MOVE9_OUT := MOVE(EN := ThirdFloor, IN := 3, ENO => _TMP_MOVE9_ENO);
  IF _TMP_MOVE9_ENO THEN
      TargetFloor := _TMP_MOVE9_OUT;
  END_IF;
  _TMP_MOVE13_OUT := MOVE(EN := FourthFloor, IN := 4, ENO => _TMP_MOVE13_ENO);
  IF _TMP_MOVE13_ENO THEN
      TargetFloor := _TMP_MOVE13_OUT;
  END_IF;
  _TMP_MOVE14_OUT := MOVE(EN := FifthFloor, IN := 5, ENO => _TMP_MOVE14_ENO);
  IF _TMP_MOVE14_ENO THEN
      TargetFloor := _TMP_MOVE14_OUT;
  END_IF;
  _TMP_GT23_OUT := GT(CurrentFloor, TargetFloor);
  _TMP_AND36_OUT := AND(Elevator, _TMP_GT23_OUT);
  TON0(IN := _TMP_AND36_OUT, PT := T#2s);
  ElevatorDown := TON0.Q;
  _TMP_LT24_OUT := LT(CurrentFloor, TargetFloor);
  _TMP_AND38_OUT := AND(Elevator, _TMP_LT24_OUT);
  TON1(IN := _TMP_AND38_OUT, PT := T#2s);
  ElevatorUp := TON1.Q;
  TP0(IN := NOT(Pulse) AND Elevator, PT := T#1s);
  Pulse := TP0.Q;
  _TMP_NE55_OUT := NE(CurrentFloor, TargetFloor);
  _TMP_AND58_OUT := AND(ElevatorUp, _TMP_NE55_OUT);
  R_TRIG1(CLK := Pulse AND _TMP_AND58_OUT);
  _TMP_NE49_OUT := NE(CurrentFloor, TargetFloor);
  _TMP_AND52_OUT := AND(ElevatorDown, _TMP_NE49_OUT);
  R_TRIG2(CLK := Pulse AND _TMP_AND52_OUT);
  CTUD0(CU := R_TRIG1.Q, CD := R_TRIG2.Q, PV := TargetFloor);
  CurrentFloor := CTUD0.CV;
  FloorReached := CTUD0.QU;
  _TMP_OR77_OUT := OR(FloorReached AND Elevator, Door);
  TP1(IN := _TMP_OR77_OUT, PT := T#2s);
  DoorOpen := TP1.Q;
  FloorReached := CTUD0.QD;
  _TMP_MOVE41_OUT := MOVE(EN := GroundFloor, IN := 0, ENO => _TMP_MOVE41_ENO);
  IF _TMP_MOVE41_ENO THEN
      TargetFloor := _TMP_MOVE41_OUT;
  END_IF;
  _TMP_EQ72_OUT := EQ(CurrentFloor, TargetFloor);
  _TMP_AND69_OUT := AND(Elevator, _TMP_EQ72_OUT);
  TP2(IN := _TMP_AND69_OUT, PT := T#2s);
  DoorOpen := TP2.Q;
  Elevator := NOT(ElevatorOff) AND ElevatorOn;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
