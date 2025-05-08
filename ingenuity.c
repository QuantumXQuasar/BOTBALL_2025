#include <kipr/wombat.h>

void moveF(double distance);
void turnRight(double angle);
void turnLeft(double angle);
void moveB(double distance);
void arm_pos(int pos);
void sensor_function();
void turn_left_one_wheel(int angle);
void turn_right_one_wheel(int angle);


int l = 3;
int r = 0;
int c = 3;
int s = 0;
int up_grab = 670; //for grabbing how up
int up_max = 450; //max height for the arm
int open = 945;
int close = 1300;
int down = 1230;
int arm_pos_now = 100;


int main()
{
    /*
    enable_servos();
    set_servo_position(c, open);
    arm_pos(up_grab);
    moveF(23);
    set_servo_position(c, close);
    msleep(500); 
    arm_pos(up_max);
    msleep(500);
    moveB(10);
    */
    turn_left_one_wheel(90);
    turn_right_one_wheel(90);

    
    return 0;
}

void moveF(double distance){ //move front
    mav(l, -1500);
    mav(r, 1500);
    msleep(distance/0.00675);
    ao();
    msleep(500);
}

void moveB(double distance){ //move Back
    mav(l, 1500);
    mav(r, -1500);
    msleep(distance/0.00675);
    ao();
    msleep(500);
}

void turnRight(double angle){
    mav(l, -1000);
    mav(r, -1000);
    msleep((1010.0/90)*angle);
    ao();
}

void turnLeft(double angle){
    mav(l, 1000);
    mav(r, 1000);
    msleep((1010.0/90)*angle);
    ao();
}

void arm_pos(int pos){
    if(pos < arm_pos_now){
        while(pos < arm_pos_now){
        	set_servo_position(s, arm_pos_now - 1);
       		arm_pos_now -= 1;
        	msleep(2);
        }
    }
    else{
        while(pos > arm_pos_now){
            set_servo_position(s, arm_pos_now + 1);
            arm_pos_now += 1;
            msleep(2);
        }
    }
}

void sensor_function(){
    int num = 0;
    while(digital(5) > 4070){
        num++;
        msleep(100);
    }
    if(num == 1){
        ao();
    }
}
    
void turn_left_one_wheel(int angle){
    mav(l, 0);
    mav(r, -1000);
    msleep((2400.0/90)*angle);
    ao();
    msleep(500);
}

void turn_right_one_wheel(int angle){
    mav(l, -1000);
    mav(r, 0);
    msleep((2400.0/90)*angle);
    ao();
    msleep(500);
}


    
