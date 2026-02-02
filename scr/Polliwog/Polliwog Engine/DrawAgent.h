#pragma once

#ifndef _DrawAgent
#define _DrawAgent

#include "Drawable.h"

class DrawAgent
{
public:

    class GameLoop
    {
    private:
        friend class DrawManager;
        static void Draw(Drawable* p) { p->Draw(); }
    };

public:
    class Registration
    {
        friend class DrawRegistrationCmd;
        friend class DrawDeregistrationCmd;

    private:
        static void SceneRegistration(Drawable* p) { p->SceneRegistration(); }
        static void SceneDeregistration(Drawable* p) { p->SceneDeregistration(); }
    };

};

#endif _DrawAgent