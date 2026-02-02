#ifndef Polliwog_H
#define Polliwog_H

#include "AzulCore.h"
#include "Colors.h"
#include "Vect.h"
#include "../User Defined Code/Frigate.h"
#include "../User Defined Code/WorldPlane.h"

class Polliwog: public Engine
{
private:
	//Singleton
	static Polliwog* ptrInstance;

	Polliwog() = default;
	Polliwog(const Polliwog&) = delete;
	Polliwog& operator=(const Polliwog&) = delete;
	~Polliwog() = default;

	static Polliwog& Instance()
	{
		if (ptrInstance == nullptr)
			ptrInstance = new Polliwog(); 
		return *ptrInstance;
	};

	virtual void Initialize();
	virtual void LoadContent();
	virtual void Update();
	virtual void Draw();
	virtual void UnLoadContent();

	void LoadResources();
	void GameIntialize();
	void GameEnd();

	//Method for setting a window
	void privSetWindowName(const char* windowName);
	void privSetWindowSize(int width, int height);
	void privSetWindowColor(Vect color);
	void privSetWindowColor(float red, float green, float blue, float opacity);

	float privGetTime();
	int privGetHeight();
	int privGetWidth();


	//Methods for creating graphics objects

	//Method for placing an object in world


public:
	//Just here while its a Singleton
	//static void funRun() { Instance().privRun(); };
	//static void run();

	static void funRun() { Instance().run(); } //Simplier

	//User Access
	static void SetWindowName(const char* name) { Instance().privSetWindowName(name); };
	static void SetWindowSize(int width, int height) { Instance().privSetWindowSize(width, height); };
	static void SetWindowColor(Vect color) { Instance().privSetWindowColor(color); };
	static void SetWindowColor(float red, float green, float blue, float opacity) { Instance().privSetWindowColor (red, green, blue, opacity); };
	static float GetTime() { return Instance().privGetTime(); };

	static int GetHeight() { return Instance().privGetHeight(); };
	static int GetWidth() { return Instance().privGetWidth(); };

	static void Terminate();

};


#endif Polliwog_H