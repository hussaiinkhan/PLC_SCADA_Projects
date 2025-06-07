PROGRAM BoxSorting
  VAR
    Start : BOOL;
    Stop : BOOL;
    Pulse : BOOL;
    MainConveyer : BOOL;
    Sensor1 : BOOL;
    Reset : BOOL;
    Sensor2 : BOOL;
    Sensor3 : BOOL;
    LeftConveyer : BOOL;
    RightConveyer : BOOL;
    MiddleConveyer : BOOL;
    SmallBoxes : INT := 0;
    TotalBoxes : INT := 0;
    SmallBoxesAlarm : BOOL;
    MediumBoxesAlarm : BOOL;
    LargeBoxesAlarm : BOOL;
    MediumBoxes : INT := 0;
    LargeBoxes : INT := 0;
    TON0 : TON;
    TON1 : TON;
    TON2 : TON;
    CTU0 : CTU;
    CTU1 : CTU;
    CTU2 : CTU;
    TP0 : TP;
    TP1 : TP;
    TP2 : TP;
    R_TRIG1 : R_TRIG;
    R_TRIG2 : R_TRIG;
    R_TRIG3 : R_TRIG;
    _TMP_ADD70_OUT : INT;
  END_VAR

  MainConveyer := NOT(Stop) AND (MainConveyer OR Start);
  TON0(IN := NOT(Pulse) AND MainConveyer, PT := T#5s);
  Sensor1 := TON0.Q;
  TON1(IN := NOT(Pulse) AND MainConveyer, PT := T#12s);
  Sensor2 := TON1.Q;
  TON2(IN := NOT(Pulse) AND MainConveyer, PT := T#17s);
  Sensor3 := TON2.Q;
  R_TRIG1(CLK := NOT(Sensor3) AND NOT(Sensor2) AND Sensor1);
  CTU0(CU := R_TRIG1.Q, R := Reset, PV := 15);
  SmallBoxes := CTU0.CV;
  SmallBoxesAlarm := CTU0.Q;
  R_TRIG2(CLK := NOT(Sensor3) AND Sensor2 AND Sensor1);
  CTU1(CU := R_TRIG2.Q, R := Reset, PV := 15);
  MediumBoxes := CTU1.CV;
  MediumBoxesAlarm := CTU1.Q;
  R_TRIG3(CLK := Sensor3 AND Sensor2 AND Sensor1);
  CTU2(CU := R_TRIG3.Q, R := Reset, PV := 15);
  LargeBoxes := CTU2.CV;
  LargeBoxesAlarm := CTU2.Q;
  TP0(IN := NOT(Sensor3) AND NOT(Sensor2) AND Sensor1, PT := T#3s);
  LeftConveyer := TP0.Q;
  TP1(IN := NOT(Sensor3) AND Sensor2 AND Sensor1, PT := T#3s);
  MiddleConveyer := TP1.Q;
  TP2(IN := Sensor3 AND Sensor2 AND Sensor1, PT := T#3s);
  RightConveyer := TP2.Q;
  Pulse := TON0.Q;
  Pulse := TON1.Q;
  Pulse := TON2.Q;
  _TMP_ADD70_OUT := ADD(SmallBoxes, MediumBoxes, LargeBoxes);
  TotalBoxes := _TMP_ADD70_OUT;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : BoxSorting;
  END_RESOURCE
END_CONFIGURATION
