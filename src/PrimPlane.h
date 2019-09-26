// Plane Geaometrical Primitive class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once

#include "Prim.h"

/**
 * @brief The Plane Geaometrical Primitive class
 */
class CPrimPlane : public CPrim
{
public:
	/**
	 * @brief Constructor
	 * @param origin Point on the plane
	 * @param normal Normal to the plane
	 */
	CPrimPlane(Vec3f origin, Vec3f normal)
		: CPrim()
		, m_normal(normal)
		, m_origin(origin)
	{
		normalize(m_normal);
	}
	virtual ~CPrimPlane(void) = default;

	virtual bool Intersect(Ray& ray) override
	{
		// --- PUT YOUR CODE HERE ---
		
		/*float tm = (m_origin - ray.org).dot(m_normal) / ray.dir.dot(m_normal);
		return true;*/

		float pl = m_normal.dot(ray.dir);

		if (pl > 1e-6)
		{
			Vec3f po = m_origin - ray.org;
			float num = po.dot(m_normal);
			ray.t = num / pl;
			return (ray.t >= 0); 		//checking range
		}

		return false;
	}
	
	
private:
	Vec3f m_normal;	///< Point on the plane
	Vec3f m_origin;	///< Normal to the plane
};
