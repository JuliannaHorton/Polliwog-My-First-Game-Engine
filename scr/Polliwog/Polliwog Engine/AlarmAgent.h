#pragma once

#ifndef _AlarmAgent
#define _AlarmAgent

#include "Alarmable.h"

class AlarmAgent
{
public:

    class GameLoop
    {
    private:
        friend class AlarmManager;
        static void TriggerAlarm(Alarmable* p) { p->TriggerAlarm(); }
    };

public:
    class Registration
    {
        friend class AlarmRegistrationCmd;
        friend class AlarmDeregistrationCmd;

    private:
        static void AlarmRegistration(float t, Alarmable* p) { p->AlarmRegistration(t); }
        static void AlarmDeregistration(Alarmable* p) { p->AlarmDeregistration(); }
    };

};

#endif _AlarmAgent