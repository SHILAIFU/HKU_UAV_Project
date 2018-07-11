#ifndef _PID_H_
#define _PID_H_

typedef struct _pid
{
    float TargetPos;
    float CurrentPos;
    float err;
    float err_last;
    float Kp, Ki, Kd;
    float OutputSpeed;
    float integral;
    float umax;
    float umin;
} Pid;

class Pid_control
{
  public:
    void PID_init(float kp, float ki, float kd, float max, float min);
    float PID_realize(float current, float target);

  private:
    int index;
    Pid pid;
};

void Pid_control::PID_init(float kp, float ki, float kd, float max, float min)
{
    pid.TargetPos = 0.0;
    pid.CurrentPos = 0.0;
    pid.err = 0.0;
    pid.err_last = 0.0;
    pid.OutputSpeed = 0.0;
    pid.integral = 0.0;
    pid.Kp = kp;
    pid.Ki = ki;
    pid.Kd = kd;
    pid.umax = max;
    pid.umin = min;
}

float Pid_control::PID_realize(float current, float target)
{
    pid.TargetPos = target;
    pid.CurrentPos = current;
    pid.err = pid.TargetPos - pid.CurrentPos;
    pid.integral += pid.err;

    pid.OutputSpeed = pid.Kp * pid.err + pid.Ki * pid.integral + pid.Kd * (pid.err - pid.err_last);
    pid.err_last = pid.err;

    if (pid.OutputSpeed > pid.umax)
        pid.OutputSpeed = pid.umax;
    if (pid.OutputSpeed < pid.umin)
        pid.OutputSpeed = pid.umin;
    return pid.OutputSpeed;
}
#endif