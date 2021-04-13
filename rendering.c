#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "headers/config.h"
#include "headers/player.h"

extern Player local_player;
extern	Vector2	linestart[128], linend[128],
		linestart_s[MAP_SIDES], linend_s[MAP_SIDES],
		border_s[4], border_e[4],
		map1_s[4], map1_e[4],
		collision_point;
float scene[360];

void view() {
	for (int i = 0; i < local_player.ray_count; i++) {
		Vector2 closest = {0};
		float record = INFINITY;
		for (int j = 0; j < MAP_SIDES; j++) {
			collision_point = (Vector2) {0, 0};
			//cast_rays(local_player.rays[i], local_player.position, map1_s[j], map1_e[j]);
			cast_rays(local_player.rays[i], local_player.position, border_s[0], border_e[0]);
			cast_rays(local_player.rays[i], local_player.position, border_s[1], border_e[1]);
			cast_rays(local_player.rays[i], local_player.position, border_s[2], border_e[2]);
			cast_rays(local_player.rays[i], local_player.position, border_s[3], border_e[3]);
			cast_rays(local_player.rays[i], local_player.position, linestart_s[j], linend_s[j]);
			if (collision_point.x && collision_point.y) {
				float distance = sqrt(pow(local_player.position.x - collision_point.x, 2) + pow(local_player.position.y - collision_point.y, 2));
				if (distance < record) {
					record = distance;
					closest = collision_point;
				}
			}
		}
		DrawLineEx(local_player.position, closest, 1 * (closest.x && closest.y), RED);
		scene[i] = record * (record != NAN);
	}
	return;
}

float map(float value, float from1, float to1, float from2, float to2) {
	return (value - from1) / (to1 - from1) * (to2 - from2) + from2;
}

void view_3d() {
	for (int i = 0; i < (int) (sizeof(scene)/sizeof(scene[0])); i++) {
		const float scene_width = WIDTH / local_player.ray_count * 1.1867;
		const float alpha = map(scene[i], 0, 200, 1, 0);
		DrawLineEx((Vector2) {i * scene_width, (scene[i] * 2)}, (Vector2) {i * scene_width, (HEIGHT - (scene[i] * 2))}, scene_width, ColorAlpha(RED, alpha));
	}
}