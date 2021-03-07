#pragma once
/*#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024
#define GRAVITY 350.0f

#define LOGO_STATE_SHOW_TIME 3.0
#define SPLASH_STATE_BACKGROUND_FILEPATH "./resources/res/Splash_Background.png"

#define MAIN_MENU_STATE_BACKGROUND_FILEPATH "./resources/res/sky.png"
#define GAME_TITLE_FILEPATH "./resources/res/title.png"
#define PLAY_BUTTON_FILEPATH "./resources/res/PlayButton.png"

#define GAME_OVER_BACKGROUND_FILEPATH "./resources/res/sky.png"

enum gameStates { ready, playing, gameOver };*/

///
#pragma once
#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024

#define LOGO_STATE_SHOW_TIME 3.0
#define SPLASH_STATE_BACKGROUND_FILEPATH "./resources/res/Splash-Background.png"

#define MAIN_MENU_STATE_BACKGROUND_FILEPATH "./resources/res/sky.png"
#define GAME_TITLE_FILEPATH "./resources/res/title.png"
#define PLAY_BUTTON_FILEPATH "./resources/res/PlayButton.png"

#define GAME_OVER_BACKGROUND_FILEPATH "./resources/res/sky.png"
#define GAME_OVER_BODY_FILEPATH "./resources/res/Game-Over-Body.png"
#define GAME_OVER_TITLE_FILEPATH "./resources/res/Game-Over-Title.png"

#define PIPE_UP_FILEPATH "./resources/res/PipeUp.png"
#define PIPE_DOWN_FILEPATH "./resources/res/PipeDown.png"
#define PIPE_MOVEMENT_SPEED 200.0f
#define PIPE_SPAWN_FREQUENCY 0.8f
#define MAX_PIPE_HEIGHT 261

#define LAND_FILEPATH "./resources/res/Land.png"

#define BIRD_FRAME_1_FILEPATH "./resources/res/BIRD-01.png"
#define BIRD_FRAME_2_FILEPATH "./resources/res/BIRD-02.png"
#define BIRD_FRAME_3_FILEPATH "./resources/res/BIRD-03.png"
#define BIRD_FRAME_4_FILEPATH "./resources/res/BIRD-04.png"

#define BIRD_ANIMATION_DURATION 0.4f

#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3

#define GRAVITY 350.0f
#define FLYING_SPEED 350.0f

#define FLYING_DURATION 0.25f

#define ROTATION_SPEED 100.0f
#define FLASH_SPEED 2000.0f

#define PIPE_SCORING_FILEPATH "./resources/res/InvisibleScoringPipe.png"
#define FLAPPY_FONT_FILEPATH "./resources/fonts/FlappyFont.ttf"

#define TIME_BEFORE_GAME_OVER_APPEARS 1.5f

#define HIGH_SCORE_FILEPATH "./resources/highScore.txt"

#define BRONZE_MEDAL_FILEPATH "./resources/res/Bronze-Medal.png"
#define SILVER_MEDAL_FILEPATH "./resources/res/Silver-Medal.png"
#define GOLD_MEDAL_FILEPATH "./resources/res/Gold-Medal.png"
#define PLATINUM_MEDAL_FILEPATH "./resources/res/Platinum-Medal.png"

#define BRONZE_MEDAL_SCORE 0
#define SILVER_MEDAL_SCORE 10
#define GOLD_MEDAL_SCORE 50
#define PLATINUM_MEDAL_SCORE 100

enum gameStates {
	ready,
	playing,
	gameOver
};

#define HIT_SOUND_FILEPATH "./resources/audio/Hit.wav"
#define POINT_SOUND_FILEPATH "./resources/audio/Point.wav"
#define WING_SOUND_FILEPATH "./resources/audio/Wing.wav"