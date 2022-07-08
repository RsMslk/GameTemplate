#include "Engine.h"
#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <cstdio>
using namespace std;
/*Enemy enemy_a = Enemy(1, 1, 1);*/
//Enemy* enemy_arr = (Enemy *) malloc(10 * sizeof(Enemy));

class Enemy {
public: 
    Enemy() {}
    Enemy(int type, int x, int y) { //Constructor
        set_type(type);
        set_x(x);
        set_y(y);
    }
    ~Enemy() {} //Destructor

    int get_type() {
        return this->type;
    }
    void set_type(int type) {
        this->type = type;
    }
    int get_x() {
        return this->x;
    }
    void set_x(int x) {
        this->x = x;
    }
    int get_y() {
        return this->y;
    }
    void set_y(int y) {
        this->y = y;
    }
    int get_spawn_time() {
        return this->spawn_time;
    }
    void set_spawn_time(int spawn_time) {
        this->spawn_time = spawn_time;
    }
    vector<int> get_hitbox_x() {
        return this->hitbox_x;
    }
    vector<int> get_hitbox_y() {
        return this->hitbox_y;
    }
    void set_hitbox_x( vector<int> hitbox_x) {
        this->hitbox_x = hitbox_x;
    }
    void set_hitbox_y(vector<int> hitbox_y) {
        this->hitbox_y = hitbox_y;
    }
private:
    int type;
    int x;
    int y;
    int spawn_time;
    vector<int> hitbox_x;
    vector<int> hitbox_y;
};

class Shot {
public:
    Shot(){}
    Shot(int type, int direction_x, int direction_y, int x_init, int y_init, int x, int y) {
        set_type(type);
        set_direction_x(direction_x);
        set_direction_y(direction_y);
        set_x_init(x_init);
        set_y_init(y_init);
        set_x(x);
        set_y(y);
    }
    ~Shot(){}
    int get_type() {
        return this->type;
    }
    void set_type(int type) {
        this->type = type;
    }
    int get_x() {
        return this->x;
    }
    void set_x(int x) {
        this->x = x;
    }
    int get_y() {
        return this->y;
    }
    void set_y(int y) {
        this->y = y;
    }
    int get_direction_x() {
        return this->direction_x;
    }
    int get_direction_y() {
        return this->direction_y;
    }
    int get_x_init() {
        return this->x_init;
    }
    int get_y_init() {
        return this->y_init;
    }
    void set_direction_x(int x) {
        this->direction_x = x;
    }
    void set_direction_y(int y) {
        this->direction_y = y;
    }
    void set_x_init(int x) {
        this->x_init = x;
    }
    void set_y_init(int x) {
        this->y_init = x;
    }
private:
    int type;
    int direction_x;
    int direction_y;
    int x_init;
    int y_init;
    int x;
    int y;
};

class Player {
public:
    Player(){}
    Player(string Name, int shots_type, int x, int y, int freq, int score) {
        set_Name(Name),
        set_shots_type(shots_type);
        set_x(x);
        set_y(y);
        set_freq(freq);
        set_score(score);
    }
    ~Player(){}
    string get_Name() {
        return this->Name;
    }
    void set_Name(string Name) {
        this->Name = Name;
    }
    int get_shots_type() {
        return this->shots_type;
    }
    void set_shots_type(int type) {
        this->shots_type = type;
    }
    int get_x() {
        return this->x;
    }
    void set_x(int x) {
        this->x = x;
    }
    int get_y() {
        return this->y;
    }
    void set_y(int y) {
        this->y = y;
    }
    int get_freq() {
        return this->freq;
    }
    void set_freq(int freq) {
        this->freq = freq;
    }
    int get_score() {
        return this->score;
    }
    void set_score(int score) {
        this->score = score;
    }
private:
    string Name;
    int shots_type;
    int x, y;
    int freq;
    int score;
};

//
//  You are free to modify this file
//

//  is_key_pressed(int button_vk_code) - check if a key is pressed,
//                                       use keycodes (VK_SPACE, VK_RIGHT, VK_LEFT, VK_UP, VK_DOWN, 'A', 'B')
//
//  get_cursor_x(), get_cursor_y() - get mouse cursor position
//  is_mouse_button_pressed(int button) - check if mouse button is pressed (0 - left button, 1 - right button)
//  clear_buffer() - set all pixels in buffer to 'black'
//  is_window_active() - returns true if window is active
//  schedule_quit_game() - quit game after act()

bool GameOver;
const int width = 976;
const int height = 632;
int score, lives;
int timer = 0;
int timer1 = 0;
int timestamp;

//HWND hwnd;

//vector<E> enemy_types = {};
vector<Enemy> enemies = {};
vector<Shot> shots = {};

Player player;
//enum eDirection {LEFT, RIGHT, UP, DOWN};
//eDirection dir;

// initialize game data in this function
void initialize()
{
  
    lives = 1;
    score = 0;
    timer = 0;
    timer1 = 0;
    GameOver = 0;
    srand(time(0));
    enemies = {};
    shots = {};
    //player("Default", 0, 500, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    player.set_Name("Default");
    player.set_score(0);
    player.set_freq(500);
    player.set_shots_type(0);
    player.set_x(SCREEN_WIDTH/2);
    player.set_y(SCREEN_HEIGHT/2);
    //enemy_types.push_back({ 1, 1000 });
    /*Enemy enemy_tmp;
    enemy_tmp.set_type(1);
    enemy_tmp.set_spawn_time(1000);
    vector <int> hitbox_x_tmp;
    vector <int> hitbox_y_tmp;
    for (int k = -4; k < 5; k++)
    {
        for (int j = -4; j < 5; j++)
        {
            if (abs(k) + abs(j) == 4 || abs(k) + abs(j) == 2)
            {
                hitbox_x_tmp.push_back(k);
                hitbox_y_tmp.push_back(j);
            }
        }
    }
    enemy_tmp.set_hitbox_x(hitbox_x_tmp);
    enemy_tmp.set_hitbox_y(hitbox_y_tmp);*/
    timestamp = 500;
}

// this function is called to update game data,
// dt - time elapsed since the previous update (in seconds)
void act(float dt)
{
    //hwnd = GetActiveWindow();
    //char szBuff[64];
    //szBuff[0] = 'A';
    //szBuff[2] = 'e';
    //sprintf_s(szBuff, "%s", hwnd);
    //MessageBox(hwnd, szBuff, "AMOGUS", MB_OK);

    
    timestamp++;
    timer++;
    timer1++;
    if (is_key_pressed(VK_ESCAPE) || lives == 0)
        GameOver = 1;
    if (GameOver == 1)
        schedule_quit_game();

    if (is_key_pressed('A') && player.get_x() > 10 + 24)
        if (timer1 % 10 == 0)
        {
            int x = player.get_x() - 1;
            player.set_x(x);
        }
    if (is_key_pressed('D') && player.get_x() < width - 10 + 24)
        if (timer1 % 10 == 0)
        {
            int x = player.get_x() + 1;
            player.set_x(x);
        }
    if (is_key_pressed('W') && player.get_y() > 10 + 68)
        if (timer1 % 10 == 0)
        {
            int y = player.get_y() - 1;
            player.set_y(y);
        }
    if (is_key_pressed('S') && player.get_y() < height - 10 + 68)
        if (timer1 % 10 == 0)
        {
            int y = player.get_y() + 1;
            player.set_y(y);
        }
    if (is_mouse_button_pressed(0) && get_cursor_x() < 1024 && get_cursor_x() > 0 && get_cursor_y() > 0 && get_cursor_y() < 768)
    {
        if (player.get_shots_type() == 0) {
            if (timestamp > player.get_freq())
            {
                Shot shot_tmp;
                shot_tmp.set_type(player.get_shots_type());
                shot_tmp.set_x_init(player.get_x());
                shot_tmp.set_y_init(player.get_y());
                shot_tmp.set_x(shot_tmp.get_x_init());
                shot_tmp.set_y(shot_tmp.get_y_init());
                int direction_x = (get_cursor_x() - shot_tmp.get_x_init());
                int direction_y = (get_cursor_y() - shot_tmp.get_y_init());
                //shot_tmp.direction_x = direction_x;
                //shot_tmp.direction_y = direction_y;
                if (direction_x * direction_x + direction_y * direction_y < 990 * 990 + 690 * 690)
                {
                    shot_tmp.set_direction_x(direction_x * sqrt((990 * 990 + 690 * 690) / (direction_x * direction_x + direction_y * direction_y)));
                    shot_tmp.set_direction_y(direction_y * sqrt((990 * 990 + 690 * 690) / (direction_x * direction_x + direction_y * direction_y)));
                }
                else
                {
                    shot_tmp.set_direction_x(direction_x);
                    shot_tmp.set_direction_y(direction_y);
                }
                shots.push_back(shot_tmp);
                timestamp = 0;
            }
        }
        if (player.get_shots_type() == 1)
        {
            player.set_freq(1000);
            if (timestamp > player.get_freq())
            {
                timestamp = 0;
                for (int j = -4; j < 4; j++)
                {
                    Shot shot_tmp;
                    shot_tmp.set_type(player.get_shots_type());


                    int direction_x = (get_cursor_x() - player.get_x());
                    int direction_y = (get_cursor_y() - player.get_y());

                    if (direction_x != 0)
                    {
                        shot_tmp.set_x_init(player.get_x() + j);
                        shot_tmp.set_y_init(player.get_y() - (direction_y * shot_tmp.get_x_init() / direction_x) / (direction_x * direction_x + direction_y * direction_y));
                    }
                    else {
                        shot_tmp.set_y_init(player.get_y() + j);
                        shot_tmp.set_x_init(player.get_x() - (direction_y * shot_tmp.get_y_init() / direction_y) / (direction_x * direction_x + direction_y * direction_y));
                    }
                    shot_tmp.set_x(shot_tmp.get_x_init());
                    shot_tmp.set_y(shot_tmp.get_y_init());

                    if (direction_x * direction_x + direction_y * direction_y < 990 * 990 + 690 * 690)
                    {
                        shot_tmp.set_direction_x(direction_x * sqrt((990 * 990 + 690 * 690) / (direction_x * direction_x + direction_y * direction_y)) + rand() % 200 * j);
                        shot_tmp.set_direction_y(direction_y * sqrt((990 * 990 + 690 * 690) / (direction_x * direction_x + direction_y * direction_y)) + rand() % 200 * j);
                    }
                    else
                    {
                        shot_tmp.set_direction_x(direction_x + rand() % 200 * j);
                        shot_tmp.set_direction_y(direction_y + rand() % 200 * j);
                    }
                    shots.push_back(shot_tmp);
                }
                
            }
        }
    }
    

    
   if (timer % 1000 == 0)
   {
       Enemy enemy_tmp;
       enemy_tmp.set_type(1);
       enemy_tmp.set_x(rand() % (width - 30) + 24);
       enemy_tmp.set_y(rand() % (height - 20) + 68);
       enemy_tmp.set_type(1);
       enemy_tmp.set_spawn_time(1000);
       vector <int> hitbox_x_tmp;
       vector <int> hitbox_y_tmp;
       for (int k = -4; k < 5; k++)
       {
           for (int j = -4; j < 5; j++)
           {
               if (abs(k) + abs(j) == 4 || abs(k) + abs(j) == 2)
               {
                   hitbox_x_tmp.push_back(k);
                   hitbox_y_tmp.push_back(j);
               }
           }
       }

       enemy_tmp.set_hitbox_x(hitbox_x_tmp);
       enemy_tmp.set_hitbox_y(hitbox_y_tmp);
       enemies.push_back(enemy_tmp);
   }

   



    
    for (int i = 0; i < shots.size(); i++) // Deleting shots when limit
    {
        if (shots[i].get_x() >= width + 24 || shots[i].get_y() >= height + 68 || shots[i].get_x() <= 24 || shots[i].get_y() <= 68)
        {
            shots.erase(shots.begin() + i);
        }
        else if (shots[i].get_type() == 1 && (shots[i].get_x() - shots[i].get_x_init()) * (shots[i].get_x() - shots[i].get_x_init()) + (shots[i].get_y() - shots[i].get_y_init()) * (shots[i].get_y() - shots[i].get_y_init()) >= 150 * 150)
        {
            shots.erase(shots.begin() + i);
        }
    }
    int i = 0;
    while  (i < shots.size() && enemies.size() > 0) // Deleting shots, when hit
    {
        for (int j = 0; j < enemies.size(); j++)
        {
            if (shots.size() == 0) {
                break;
            }
            if (abs(shots[i].get_x() - enemies[j].get_x() )< 5 && abs(shots[i].get_y() - enemies[j].get_y()) < 5)
            {
                shots.erase(shots.begin() + i);
                
                if (i > 0) {
                    i--;
                }
                enemies.erase(enemies.begin() + j);
                j--;
                
                score += 25;
                player.set_score(player.get_score() + 25);
            }
                      
        }
        i++;
    }
    /*for (int i = 0; i < shots_indexes.size(); i++)
    {
        
    }
    for (int i = 0; i < enemy_indexes.size(); i++)
    {
        
        ;
    }*/

    
     
    
    
    for (int i = 0; i < shots.size(); i++)
    {
        if (timer % 80 == 0)
        {
            shots[i].set_x(shots[i].get_x() + shots[i].get_direction_x() / 150);
            shots[i].set_y(shots[i].get_y() + shots[i].get_direction_y() / 150);
        }
    }

    for (int i = 0; i < enemies.size(); i++)
    {
        for (int j = 0; j < enemies.size(); j++)
        {
            int dir_x = player.get_x() - enemies[i].get_x();
            int dir_y = player.get_y() - enemies[i].get_y();
            int sign_x = 0;
            int sign_y = 0;
            if (dir_x < 0)
            {
                sign_x = -1;
            }
            if (dir_x > 0)
            {
                sign_x = 1;
            }
            if (dir_y < 0)
            {
                sign_y = -1;
            }
            if (dir_y > 0)
            {
                sign_y = 1;
            }            
            if (i != j && abs(enemies[i].get_x() - enemies[j].get_x()) < 6 && abs(enemies[i].get_x() - player.get_x()) < abs(enemies[j].get_x() - player.get_x())) {
                enemies[i].set_x(enemies[i].get_x() + sign_x);
            }
            if (i != j && abs(enemies[i].get_y() - enemies[j].get_y()) < 6 && abs(enemies[i].get_y() - player.get_y()) < abs(enemies[j].get_y() - player.get_y())) {
                enemies[i].set_y(enemies[i].get_y() + sign_y);
            }
        }
    }
    for (int i = 0; i < enemies.size(); i++)
    {
        if (timer % 50 == 0)
        {
            if (enemies[i].get_type() == 1)
            {
                int dir_x = player.get_x() - enemies[i].get_x();
                int dir_y = player.get_y() - enemies[i].get_y();
                int sign_x = 0;
                int sign_y = 0;
                if (dir_x < 0)
                {
                    sign_x = -1;
                }
                if (dir_x > 0)
                {
                    sign_x = 1;
                }
                if (dir_y < 0)
                {
                    sign_y = -1;
                }
                if (dir_y > 0)
                {
                    sign_y = 1;
                }
                if (abs(dir_x) <= 3 && dir_x != 0)
                {
                    enemies[i].set_x(enemies[i].get_x() + dir_x);
                }
                else if (abs(dir_y) <= 3 && dir_y != 0)
                {
                    enemies[i].set_y(enemies[i].get_y() + dir_y);
                } 
                else if (abs(dir_x) <= 100 && abs(dir_y) <= 100)
                {
                        /*dir_x = dir_x * 2 * 100 * 100 / (dir_x * dir_x + dir_y * dir_y + 1);
                        dir_y = dir_y * 2 * 100 * 100 / (dir_x * dir_x + dir_y * dir_y + 1);*/
                    enemies[i].set_x( enemies[i].get_x() + 3 * sign_x);
                    enemies[i].set_y( enemies[i].get_y() + 3 * sign_y);
                }
                else
                {
                    enemies[i].set_x(enemies[i].get_x() + 3 * sign_x);
                    enemies[i].set_y(enemies[i].get_y() + 3 * sign_y);
                        //enemies[i].x += 3 * sign_x;
                        //enemies[i].y += 3 * sign_y;
                }
                
            }
        }
    }
    for (int i = 0; i < enemies.size(); i++)
    {
        if (abs(enemies[i].get_x() - player.get_x()) < 15 && abs(enemies[i].get_y() - player.get_y()) < 15)
        {
            lives--;
            enemies.erase(enemies.begin() + i);
        }
    }
    if (score == 100 +  player.get_shots_type() * 300)
    {
        player.set_shots_type(player.get_shots_type() + 1);
        lives++;
        score = 0;
        timestamp = 1001;
    }

}

// fill buffer in this function
// uint32_t buffer[SCREEN_HEIGHT][SCREEN_WIDTH] - is an array of 32-bit colors (8 bits per R = i , G = j, B = K) white = 256 * 256 * 256 - 1; 
void draw()
{
    // clear backbuffer
    memset(buffer, 0, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(uint32_t));
    char Score[6] = "Score";
    
    //sprintf(Score, "%p", hwnd);
    //memset(buffer, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(uint32_t));
    for (int j = 0; j < height; j++)
        for (int i = 0; i < width; i++)
        {
            buffer[j+68][24] = (256 * 256 * 256 - 1);
            buffer[68][i+24] = (256 * 256 * 256 - 1);
            buffer[j+68][width - 1 + 24] = (256 * 256 * 256 - 1);
            buffer[height +68 - 1][i + 24] = (256 * 256 * 256 - 1);
        }
    for (int i = -10; i < 10; i++)
        for (int j = -10; j < 10; j++)
            buffer[player.get_y() + i][player.get_x() + j] = (255 * 256 * 256 + 255 * 256 + 51);
    
    for (int k = 0; k < shots.size(); k++)
        for (int i = -2; i < 2; i++)
            for (int j = -2; j < 2; j++)
                buffer [shots[k].get_y() + i][shots[k].get_x() + j] = (256 * 128 * 2 - 1);
        //for (int j = -5; j < 5; j++)
        //    for (int i = -5 + j; i < 5 +j; i++)
          //      buffer[enemy_y[0] + j][enemy_x[0] + i] = (256 * 256 * 1 - 1);
    for (int k = 0; k < enemies.size(); k++)
    {
        for (int j = 0; j < 1/*enemy_types.size()*/; j++)
        {
            if (enemies[k].get_type() == 1/*enemy_types[j].type*/)
            {
                for (int i = 0; i < enemies[k].get_hitbox_x().size(); i++)
                {
                    buffer[enemies[k].get_y() + enemies[k].get_hitbox_y()[i]][enemies[k].get_x() + enemies[k].get_hitbox_x()[i]] = 204 * 256 * 256 + 51 * 256 + 153;
                }
            }
        }
    }
}

// free game data in this function
void finalize()
{
    memset(buffer, 0, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(uint32_t));
}

