#pragma once
#define _WIN32_WINNT 0x0501
#include "auxiliar.h"
#include "client.h"
#include "server.h"
#include "animation.h"
bool iniciar(vector <string> &direcciones, string mi_ip);
bool escuchar(vector <string> &direcciones);
