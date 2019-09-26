// Perspective Camera class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once

#include "ICamera.h"

/**
 * @brief Perspective Camera class
 */
class CCameraPerspective : public ICamera
{
public:
	/**
	 * @brief Constructor
	 * @param pos Camera origin (center of projection)
	 * @param dir Camera viewing direction
	 * @param up Up-vector
	 * @param angle (Vertical) full opening angle of the viewing frustum (in degrees)
	 * @param resolution The image resolution
	 */
	CCameraPerspective(Vec3f pos, Vec3f dir, Vec3f up, float angle, Size resolution)
		: ICamera(resolution)
		, m_pos(pos)
		, m_dir(dir)
		, m_up(up)
	{
		// --- PUT YOUR CODE HERE ---
		m_zAxis = normalize(dir);
		m_xAxis = normalize(up * m_zAxis);
		m_yAxis = normalize(m_xAxis * m_zAxis);
		m_aspect = resolution.width / float(resolution.height);

		// opening angle:
		float angleInRad = angle * (float)M_PI / 180.f;
		m_focus = 1.f / tan(angleInRad / 2.f);
		
        /*for(int i = 0; i < resolution.height;i++)
            {
            for(int j = 0; j < resolution.width;j++)
            {
            float ndcx= (i + 0.5) / resolution.width;
            float ndcy= (j + 0.5) /resolution.width;
            // Screen space coordinates [-1, 1]
            float sscx= 2 *ndcx-1;
            float sscy= 2 * ndcy-1;
            dir = sscx*i+ sscy*j+ ICamera->pos - ICamera->dir;
            normalize(dir); // May normalize here
            // Trace ray and assign color to pixel
            
            }
            }*/
		
	}
	virtual ~CCameraPerspective(void) = default;

	virtual bool InitRay(float x, float y, Ray& ray) override
	{
		// --- PUT YOUR CODE HERE ---
		ray.org = m_pos;
		ray.dir = (m_xAxis * (2.0f * ((x / (float)getResolution().width - .5f) * m_aspect))) + 
						(m_yAxis * (2.0f * (y / (float)getResolution().height - .5f))) + (m_zAxis * m_focus);
		ray.dir = normalize(ray.dir);
		//return true;
	}


private:
	// input values
	Vec3f m_pos;
	Vec3f m_dir;
	Vec3f m_up;

	// preprocessed values
	float m_focus;
	Vec3f m_xAxis;
	Vec3f m_yAxis;
	Vec3f m_zAxis;
	float m_aspect;
};

