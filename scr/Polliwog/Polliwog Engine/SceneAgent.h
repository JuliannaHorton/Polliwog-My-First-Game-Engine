#pragma once

#ifndef _SceneAgent
#define _SceneAgent

#include "Scene.h"

class SceneAgent
{
public:

    class GameLoop
    {
    private:
        friend class SceneManager;
        static void Update(Scene* p) { p->Update(); }

        static void Draw(Scene* p) { p->Draw(); }
    };

public:
    class Xables
    {
        friend class Updatable;
        friend class Drawable;
        friend class Alarmable;

    private:
        static void Register(Updatable* a, UpdateManager::StorageListRef& deleteMe, Scene* p) { p->Register(a, deleteMe); }
        static void Deregister(const UpdateManager::StorageListRef& ref, Scene* p) { p->Deregister(ref); }

        static void Register(Drawable* a, DrawManager::StorageListRef& deleteMe, Scene* p) { p->Register(a, deleteMe); }
        static void Deregister(const DrawManager::StorageListRef& ref, Scene* p) { p->Deregister(ref); }

        static void Register(float t, Alarmable* a, AlarmManager::StorageListRef& deleteMe, Scene* p) { p->Register(t, a, deleteMe); }
        static void Deregister(Scene* p, AlarmManager::StorageListRef& ref) { p->Deregister(ref); }
    
        static void SubmitCommand(Scene* p, SceneCommand* cmd) { { p->SubmitCommand(cmd); } }
    };

};

#endif _SceneAgent