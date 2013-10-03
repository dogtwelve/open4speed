#ifndef COMMON_H
#define COMMON_H

#include "stdafx.h"

/**
 * @brief The game resources
 */
extern std::vector<char*> carList;     ///< List of all cars
extern std::vector<texture*> images;   ///< List of all images
extern std::vector<char*> musicList;   ///< List of all songs
extern std::vector<char*> textList;    ///< List of all texts
extern std::vector<char*> trackList;   ///< List of all tracks
extern std::vector<char*> syntaxList;  ///< List of syntax to do
extern std::vector<shader*> shaders;   ///< Shaders storage
extern std::vector<texture*> textures; ///< Textures storage
extern texture *gray;                   ///< Gray color

/**
 * @brief The engineConfig struct
 */
extern float aiCameraDistance;                                 ///< AI camera distance
extern float aiRacerFutureStep;                                ///< AI navigation parameter
extern float aiRacerFutureStepCount;                           ///< AI navigation parameter
extern float aiRacerReverseDelay;                              ///< AI navigation parameter
extern float aiRacerReverseDuration;                           ///< AI navigation parameter
extern float aiRacerSafeAngle;                                 ///< AI navigation parameter
extern float aiRacerSafeDistance;                              ///< AI navigation parameter
extern float aiRacerSafeDistanceSpeedDependency;               ///< AI navigation parameter
extern float aiRacerSafeGapGas;                                ///< AI navigation parameter
extern float aiRacerSafeGapSteering;                           ///< AI navigation parameter
extern float aiRacerSafeSpeed;                                 ///< AI navigation parameter
extern float aiRacerSteeringGapLevel1;                         ///< AI navigation parameter
extern float aiRacerSteeringGapLevel2;                         ///< AI navigation parameter
extern float aiRacerTrackUpdate;                               ///< AI navigation parameter
extern float aiRacerTrackUpdateSpeedDependency;                ///< AI navigation parameter
extern float aiTrafficFutureStep;                              ///< AI navigation parameter
extern float aiTrafficSafeAngle;                               ///< AI navigation parameter
extern float aiTrafficSafeDistance;                            ///< AI navigation parameter
extern float aiTrafficSafeDistanceSpeedDependency;             ///< AI navigation parameter
extern float aiTrafficSafeGap;                                 ///< AI navigation parameter
extern float aiTrafficSafeSpeed;                               ///< AI navigation parameter
extern float aiTrafficSpeedBrake;                              ///< AI navigation parameter
extern float aiTrafficSpeedNoGas;                              ///< AI navigation parameter
extern float aiTrafficSteeringGapLevel1;                       ///< AI navigation parameter
extern float aiTrafficSteeringGapLevel2;                       ///< AI navigation parameter
extern float aiTrafficTrackUpdate;                             ///< AI navigation parameter
extern float fontMoveX;                                        ///< Font spaces
extern float fontMoveY;                                        ///< Font spaces
extern float fontRows;                                         ///< Font rows in texture file
extern float fontSize;                                         ///< Font size
extern float fontSpaces;                                       ///< Font spaces
extern char* fontTexture;                                      ///< Texture for font
extern char* gameMode;                                         ///< Screen mode
extern char* inputController;                                  ///< Input controller
extern float keyBack;                                          ///< Keycode
extern float keyCameraDown;                                    ///< Keycode
extern float keyCameraUp;                                      ///< Keycode
extern float keyDown;                                          ///< Keycode
extern float keyGearDown;                                      ///< Keycode
extern float keyGearUp;                                        ///< Keycode
extern float keyLeft;                                          ///< Keycode
extern float keyRight;                                         ///< Keycode
extern float keyUp;                                            ///< Keycode
extern float minimalPerspective;                               ///< Minimal perspective
extern float maximalPerspective;                               ///< Maximal perspective
extern float perspectiveSpeedDependency;                       ///< Perspective change speed dependency
extern float perspectiveSpeedFollow;                           ///< Perspective change speed
extern float playerCameraMaximalDistance;                      ///< Canera maximal distance
extern float playerCameraMinimalDistance;                      ///< Camera minimal distance
extern float playerCameraStep;                                 ///< Camera move step
extern float playerDefaultCameraDistance;                      ///< Camera distance
extern float playerTrackUpdate;                                ///< GPS navigation
extern char* physicalEngine;                                   ///< Used physical engine
extern char* screenRenderer;                                   ///< Used renderer
extern char* soundCrash;                                       ///< Crash sound file
extern float soundCrashMinimalSpeed;                           ///< Crash sound minimal speed
extern float soundCrashOnSpeedChange;                          ///< Crash sound detection value
extern char* soundEngine;                                      ///< Engine sound file
extern float soundEngineFreqAspect;                            ///< Engine frequency aspect
extern float soundMaximalDistance;                             ///< Maximal distance of sounds
extern float speedAspect;                                      ///< Speed aspect
extern float viewDistance;                                     ///< View distance


/**
 * The menu
 */
extern float aspect;                   ///< Menu aspect
extern int background;                 ///< Menu background index
extern bool busy;                      ///< Busy information
extern bool click;                     ///< Click information
extern std::vector<button> buttons;    ///< List of buttons
extern bool debug;                     ///< Debug mode
extern char esc[32];                   ///< Syntax to exec on esc
extern int exec;                       ///< Exec information
extern char finish[32];                ///< Syntax to exec on finish
extern int mouseX;                     ///< Mouse position
extern int mouseY;                     ///< Mouse position
extern bool race;                      ///< Race mode
extern int screen_width;               ///< Screen width
extern int screen_height;              ///< Screen height
extern char timeoutAction[32];
extern bool transmission;              ///< Transmision state
extern int unlock;                     ///< Locking
extern int variable;                   ///< Variable for scripts
extern bool viewCar;                   ///< View car in menu
extern bool updated;                   ///< Information about updates

/**
 * The scene
 */
extern int timeout;
extern int playerCar;                  ///< Index of player car
extern float antialiasing;             ///< antialiasing level
extern bool active;        ///< Information if scene is active
extern int currentTrack;   ///< Current track index
extern int opponentCount;  ///< Opponent count
extern model *trackdata;   ///< Track first model
extern model *trackdata2;  ///< Track second model
extern model *skydome;     ///< Skydome model
const int carLimit = 8;                 ///< Maximum cars in game
extern car *allCar[carLimit];           ///< All cars in scene instances
extern int carCount;                    ///< Amount of cars in scene
extern int cameraCar;                   ///< Car camera index
extern float soundVolume;               ///< Sound volume
extern sound* crash;                    ///< Crash sound
extern sound* engine;                   ///< Engine sound
extern sound* noise;                    ///< N2O sound
extern float *mat;
extern char *string;
extern int testUniform;

const int configSize = 32;                          ///< Amount of config variables
extern int config[configSize];                      ///< Temporary config data
extern std::vector<char*> configText[configSize];   ///< Config texts
extern float direction;                             ///< Camera direction
extern float mtime;                                 ///< Time stamp
extern int lastkey;

extern physics *physic;    ///< Physical engine instance
extern renderer *xrenderer;///< Renderer instance
extern sound *music;       ///< Current song
#ifndef ANDROID
extern zip* APKArchive;
#endif

#endif // COMMON_H
