#pragma once

#ifndef _UpdateAgent
#define _UpdateAgent

#include "Updatable.h"

class UpdateAgent
{
public:

    class GameLoop
    {
    private:
        friend class UpdateManager;
        static void Update(Updatable* p) { p->Update(); }
    };

public:
    class Registration
    {
        friend class UpdateRegistrationCmd;
        friend class UpdateDeregistrationCmd;

    private:
        static void SceneRegistration(Updatable* p) { p->SceneRegistration(); }
        static void SceneDeregistration(Updatable* p) { p->SceneDeregistration(); }
    };

};

#endif _UpdateAgent
