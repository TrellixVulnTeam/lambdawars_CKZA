//=============================================================================//
// This file is automatically generated. CHANGES WILL BE LOST.
//=============================================================================//
#include "cbase.h"
#include "srcpy.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

using namespace boost::python;

// The init method is in one of the generated files declared
#ifdef _WIN32
extern "C" __declspec(dllexport) void initsrcbuiltins();
extern "C" __declspec(dllexport) void init_srcbase();
extern "C" __declspec(dllexport) void init_vmath();
extern "C" __declspec(dllexport) void init_filesystem();
extern "C" __declspec(dllexport) void init_animation();
extern "C" __declspec(dllexport) void init_entities();
extern "C" __declspec(dllexport) void init_entitiesmisc();
extern "C" __declspec(dllexport) void init_gameinterface();
extern "C" __declspec(dllexport) void init_utils();
extern "C" __declspec(dllexport) void init_physics();
extern "C" __declspec(dllexport) void init_sound();
extern "C" __declspec(dllexport) void init_particles();
extern "C" __declspec(dllexport) void initmaterials();
extern "C" __declspec(dllexport) void init_gamerules();
extern "C" __declspec(dllexport) void init_te();
extern "C" __declspec(dllexport) void init_fow();
extern "C" __declspec(dllexport) void initunit_helper();
extern "C" __declspec(dllexport) void init_steam();
extern "C" __declspec(dllexport) void init_navmesh();
extern "C" __declspec(dllexport) void init_ndebugoverlay();
extern "C" __declspec(dllexport) void initvprof();
extern "C" __declspec(dllexport) void init_srctests();
extern "C" __declspec(dllexport) void initmatchmaking();
#else
extern "C"  void initsrcbuiltins();
extern "C"  void init_srcbase();
extern "C"  void init_vmath();
extern "C"  void init_filesystem();
extern "C"  void init_animation();
extern "C"  void init_entities();
extern "C"  void init_entitiesmisc();
extern "C"  void init_gameinterface();
extern "C"  void init_utils();
extern "C"  void init_physics();
extern "C"  void init_sound();
extern "C"  void init_particles();
extern "C"  void initmaterials();
extern "C"  void init_gamerules();
extern "C"  void init_te();
extern "C"  void init_fow();
extern "C"  void initunit_helper();
extern "C"  void init_steam();
extern "C"  void init_navmesh();
extern "C"  void init_ndebugoverlay();
extern "C"  void initvprof();
extern "C"  void init_srctests();
extern "C"  void initmatchmaking();
#endif // _WIN32

// The append function
void AppendSharedModules()
{
	APPEND_MODULE(srcbuiltins)
	APPEND_MODULE(_srcbase)
	APPEND_MODULE(_vmath)
	APPEND_MODULE(_filesystem)
	APPEND_MODULE(_animation)
	APPEND_MODULE(_entities)
	APPEND_MODULE(_entitiesmisc)
	APPEND_MODULE(_gameinterface)
	APPEND_MODULE(_utils)
	APPEND_MODULE(_physics)
	APPEND_MODULE(_sound)
	APPEND_MODULE(_particles)
	APPEND_MODULE(materials)
	APPEND_MODULE(_gamerules)
	APPEND_MODULE(_te)
	APPEND_MODULE(_fow)
	APPEND_MODULE(unit_helper)
	APPEND_MODULE(_steam)
	APPEND_MODULE(_navmesh)
	APPEND_MODULE(_ndebugoverlay)
	APPEND_MODULE(vprof)
	APPEND_MODULE(_srctests)
	APPEND_MODULE(matchmaking)
}
