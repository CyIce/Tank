#pragma once
#include<stdlib.h>

#include "my_struct.h"
#include "global.h"
#include "prefabs.h"
#include "collision.h"
#include "AI.h"

//����Ϸ�����һ��̹�ˣ�
void tankAdd(Vector3i vec,GLint mark);

//����̹���ƶ���
void tankMoving(GLint value);

//��ʾ̹�ˣ�
void tankShowing();

//����̹�ˣ�
void tankDelete();