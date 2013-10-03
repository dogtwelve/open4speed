#include "stdafx.h"


/**
 * @brief The game resources
 */
std::vector<char*> carList;       ///< List of all cars
std::vector<texture*> images = *(new std::vector<texture*>());  ///< List of all images
std::vector<char*> musicList;     ///< List of all songs
std::vector<char*> textList;      ///< List of all texts
std::vector<char*> trackList;     ///< List of all tracks
std::vector<char*> syntaxList;    ///< List of syntax to do
std::vector<shader*> shaders = *(new std::vector<shader*>());   ///< Shaders storage
std::vector<texture*> textures = *(new std::vector<texture*>());///< Textures storage
texture *gray = new rgb(0.5, 0.5, 0.5, 1.0);    ///< Gray color

/**
 * @brief The engine configs
 */
float aiCameraDistance;                                 ///< AI camera distance
float aiRacerFutureStep;                                ///< AI navigation parameter
float aiRacerFutureStepCount;                           ///< AI navigation parameter
float aiRacerReverseDelay;                              ///< AI navigation parameter
float aiRacerReverseDuration;                           ///< AI navigation parameter
float aiRacerSafeAngle;                                 ///< AI navigation parameter
float aiRacerSafeDistance;                              ///< AI navigation parameter
float aiRacerSafeDistanceSpeedDependency;               ///< AI navigation parameter
float aiRacerSafeGapGas;                                ///< AI navigation parameter
float aiRacerSafeGapSteering;                           ///< AI navigation parameter
float aiRacerSafeSpeed;                                 ///< AI navigation parameter
float aiRacerSteeringGapLevel1;                         ///< AI navigation parameter
float aiRacerSteeringGapLevel2;                         ///< AI navigation parameter
float aiRacerTrackUpdate;                               ///< AI navigation parameter
float aiRacerTrackUpdateSpeedDependency;                ///< AI navigation parameter
float aiTrafficFutureStep;                              ///< AI navigation parameter
float aiTrafficSafeAngle;                               ///< AI navigation parameter
float aiTrafficSafeDistance;                            ///< AI navigation parameter
float aiTrafficSafeDistanceSpeedDependency;             ///< AI navigation parameter
float aiTrafficSafeGap;                                 ///< AI navigation parameter
float aiTrafficSafeSpeed;                               ///< AI navigation parameter
float aiTrafficSpeedBrake;                              ///< AI navigation parameter
float aiTrafficSpeedNoGas;                              ///< AI navigation parameter
float aiTrafficSteeringGapLevel1;                       ///< AI navigation parameter
float aiTrafficSteeringGapLevel2;                       ///< AI navigation parameter
float aiTrafficTrackUpdate;                             ///< AI navigation parameter
float fontMoveX;                                        ///< Font spaces
float fontMoveY;                                        ///< Font spaces
float fontRows;                                         ///< Font rows in texture file
float fontSize;                                         ///< Font size
float fontSpaces;                                       ///< Font spaces
char* fontTexture;                                      ///< Texture for font
char* gameMode;                                         ///< Screen mode
char* inputController;                                  ///< Input controller
float keyBack;                                          ///< Keycode
float keyCameraDown;                                    ///< Keycode
float keyCameraUp;                                      ///< Keycode
float keyDown;                                          ///< Keycode
float keyGearDown;                                      ///< Keycode
float keyGearUp;                                        ///< Keycode
float keyLeft;                                          ///< Keycode
float keyRight;                                         ///< Keycode
float keyUp;                                            ///< Keycode
float minimalPerspective;                               ///< Minimal perspective
float maximalPerspective;                               ///< Maximal perspective
float perspectiveSpeedDependency;                       ///< Perspective change speed dependency
float perspectiveSpeedFollow;                           ///< Perspective change speed
float playerCameraMaximalDistance;                      ///< Canera maximal distance
float playerCameraMinimalDistance;                      ///< Camera minimal distance
float playerCameraStep;                                 ///< Camera move step
float playerDefaultCameraDistance;                      ///< Camera distance
float playerTrackUpdate;                                ///< GPS navigation
char* physicalEngine;                                   ///< Used physical engine
char* screenRenderer;                                   ///< Used renderer
char* soundCrash;                                       ///< Crash sound file
float soundCrashMinimalSpeed;                           ///< Crash sound minimal speed
float soundCrashOnSpeedChange;                          ///< Crash sound detection value
char* soundEngine;                                      ///< Engine sound file
float soundEngineFreqAspect;                            ///< Engine frequency aspect
float soundMaximalDistance;                             ///< Maximal distance of sounds
float speedAspect;                                      ///< Speed aspect
float viewDistance;                                     ///< View distance

/**
 * The menu
 */
float aspect;                   ///< Menu aspect
int background;                 ///< Menu background index
bool busy;                      ///< Busy information
bool click;                     ///< Click information
std::vector<button> buttons = *(new std::vector<button>);    ///< List of buttons
bool debug;                     ///< Debug mode
char esc[32];                   ///< Syntax to exec on esc
int exec;                       ///< Exec information
char finish[32];                ///< Syntax to exec on finish
int mouseX;                     ///< Mouse position
int mouseY;                     ///< Mouse position
bool race;                      ///< Race mode
int screen_width;               ///< Screen width
int screen_height;              ///< Screen height
char timeoutAction[32];
bool transmission;              ///< Transmision state
int unlock;                     ///< Locking
int variable;                   ///< Variable for scripts
bool viewCar;                   ///< View car in menu
bool updated;                   ///< Information about updates

/**
 * The scene
 */
int timeout = 0;
int playerCar;                  ///< Index of player car
float antialiasing = 0.5f;      ///< antialiasing level
bool active;        ///< Information if scene is active
int currentTrack;   ///< Current track index
int opponentCount;  ///< Opponent count
model *trackdata;   ///< Track first model
model *trackdata2;  ///< Track second model
model *skydome;     ///< Skydome model
car *allCar[carLimit];           ///< All cars in scene instances
int carCount;                    ///< Amount of cars in scene
int cameraCar;                   ///< Car camera index
float soundVolume;               ///< Sound volume
sound* crash;                    ///< Crash sound
sound* engine;                   ///< Engine sound
sound* noise;                    ///< N2O sound
float *mat = new float[16];
char *string = new char[1024];
int testUniform = 0;

int config[configSize];                      ///< Temporary config data
std::vector<char*> configText[configSize];   ///< Config texts
float direction;                             ///< Camera direction
float mtime;                                 ///< Time stamp
int lastkey;

physics *physic;    ///< Physical engine instance
renderer *xrenderer; ///< Renderer instance
sound *music = 0;   ///< Current song
#ifndef ANDROID
zip* APKArchive;
#endif
