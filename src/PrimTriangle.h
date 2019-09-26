// Triangle Geaometrical Primitive class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once

#include "Prim.h"

/**
 * @brief Triangle Geaometrical Primitive class
 */
class CPrimTriangle : public CPrim
{
public:
	/**
	 * @brief Constructor
	 * @param a Position of the first vertex
	 * @param b Position of the second vertex
	 * @param c Position of the third vertex
	 */
	CPrimTriangle(Vec3f a, Vec3f b, Vec3f c)
		: CPrim()
		, m_a(a)
		, m_b(b)
		, m_c(c)
  	{}
	virtual ~CPrimTriangle(void) = default;
	
	virtual bool Intersect(Ray& ray) override
	{
		// --- PUT YOUR CODE HERE ---
		//Vec3f N = cross(m_a,m_b);
		Vec3f N = m_a.cross(m_b);
		//normalize(cross(a,b));
		normalize(N);
		float D = N.dot(m_a);
		//float t = - (dot(N, ray.org) + D) / dot(N, ray.dir); 
		float t = - (N.dot(ray.org) + D)/ (N.dot(ray.dir));
		if (t < 0)
		{
			return false;
		}
		Vec3f P = ray.org + t * ray.dir; 
		//Vec3f Phit = origin + t * dir; 
	Vec3f X; 

// edge 0
    Vec3f edge0 = m_b -m_a; 
    Vec3f vp0 = P - m_a; 
    X = edge0.cross(m_a); 
    if (N.dot(X)< 0) 
	{return false; }// P is on the right side 
 
    // edge 1
    Vec3f edge1 = m_c-m_b; 
    Vec3f vp1 = P - m_b; 
    X = edge1.cross(m_b); 
    if (N.dot(X) < 0)  
	{return false;} // P is on the right side 
 
    // edge 2
    Vec3f edge2 = m_a-m_c; 
    Vec3f vp2 = P - m_c; 
    X = edge2.cross(m_c); 
    if (N.dot(X) < 0) 
	{return false;} // P is on the right side; 
		return true;
	}

	
private:
	Vec3f m_a;	///< Position of the first vertex
	Vec3f m_b;	///< Position of the second vertex
	Vec3f m_c;	///< Position of the third vertex
};
