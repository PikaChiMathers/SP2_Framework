#ifndef MAIN_MENU
#define MAIN_MENU

#include "Scene.h"
#include "Camera4.h"
#include "Mesh.h"
#include "MatrixStack.h"
#include "Vertex.h"
#include "Light.h"
#include "Maps.h"
#include "GameObject.h"
#include "Shop.h"
#include <sstream>

class MainMenu : public Scene
{
public:
	MainMenu();
	~MainMenu();

	virtual void Init();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();
	int UI_height, UI_width;

	enum GEOMETRY_TYPE //added (Step 1)
	{
		GEO_AXES = 0,
		GEO_UI,
		NUM_GEOMETRY,
	};

	enum UNIFORM_TYPE
	{
		U_MVP = 0,
		U_MODELVIEW,
		U_MODELVIEW_INVERSE_TRANSPOSE,
		U_MATERIAL_AMBIENT,
		U_MATERIAL_DIFFUSE,
		U_MATERIAL_SPECULAR,
		U_MATERIAL_SHININESS,
		U_LIGHT0_POSITION,
		U_LIGHT0_COLOR,
		U_LIGHT0_POWER,
		U_LIGHT0_KC,
		U_LIGHT0_KL,
		U_LIGHT0_KQ,
		U_LIGHT0_TYPE,
		U_LIGHT0_SPOTDIRECTION,
		U_LIGHT0_COSCUTOFF,
		U_LIGHT0_COSINNER,
		U_LIGHT0_EXPONENT,

		U_LIGHTENABLED,
		U_NUMLIGHTS,

		U_COLOR_TEXTURE_ENABLED,
		U_COLOR_TEXTURE,

		U_TEXT_ENABLED,
		U_TEXT_COLOR,

		U_TOTAL,
	};

	enum LIGHT_TYPES
	{
		LIGHT1 = 0,
		NUM_LIGHTS,
	};


private: //added (Step 2)
	Camera4 camera;
	Light lights[NUM_LIGHTS];

	Maps map;

	bool scene_change;
	bool buttonPressed;
	bool spacePressed;

	unsigned m_vertexArrayID;

	Mesh* meshList[NUM_GEOMETRY];

	MS modelStack, viewStack, projectionStack;

	void RenderMesh(Mesh* mesh, bool enableLight);

	void RenderMeshOnScreen(Mesh* mesh, int x, int y, int sizex, int sizey);
		
	unsigned m_parameters[U_TOTAL];
	unsigned m_programID;
};

#endif