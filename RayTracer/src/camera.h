#pragma once
#include "common.h"

class Camera {
public:

	Camera() {
		auto aspect_ratio = 16.0 / 9.0;
		auto viewport_height = 2.0;
		auto viewport_width = aspect_ratio * viewport_height;
		auto focal_length = 1.0;

		origin = Point3f(0, 0, 0);
		horizontal = Vec3f(viewport_width, 0.0, 0.0);
		vertical = Vec3f(0.0, viewport_height, 0.0);
		lower_left_corner = origin - horizontal / 2 - vertical / 2 - Vec3f(0, 0, focal_length);
	}

	Ray Get_Ray(double u, double v) const {
		return Ray(origin, lower_left_corner + u * horizontal + v * vertical - origin);
	}

private:
	Point3f origin;
	Vec3f horizontal;
	Vec3f vertical;
	Vec3f lower_left_corner;
};