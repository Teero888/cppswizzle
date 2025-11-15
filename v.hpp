#ifndef VEC3_HPP
#define VEC3_HPP

struct vec2;
struct vec3;

template <typename ParentVec, int I0, int I1> struct SwizzleProxy2 {
  ParentVec &v;
  SwizzleProxy2(ParentVec &parent) : v(parent) {}
  operator vec2() const;
  SwizzleProxy2 &operator=(const vec2 &other);
};

template <int I0, int I1, int I2> struct SwizzleProxy3 {
  vec3 &v;

  SwizzleProxy3(vec3 &parent) : v(parent) {}

  operator vec3() const;

  SwizzleProxy3 &operator=(const vec3 &other);
};

struct vec2 {
  union {
    float data[2];

    struct {
      float x, y;
    };

    struct {
      float r, g;
    };
  };

  SwizzleProxy2<vec2, 0, 0> xx;
  SwizzleProxy2<vec2, 0, 1> xy;
  SwizzleProxy2<vec2, 1, 0> yx;
  SwizzleProxy2<vec2, 1, 1> yy;

  vec2() : x(0), y(0), xx(*this), xy(*this), yx(*this), yy(*this) {}

  vec2(float x_val, float y_val)
      : x(x_val), y(y_val), xx(*this), xy(*this), yx(*this), yy(*this) {}

  vec2(const vec2 &other)
      : x(other.x), y(other.y), xx(*this), xy(*this), yx(*this), yy(*this) {}

  vec2 &operator=(const vec2 &other) {
    if (this == &other) {
      return *this;
    }
    x = other.x;
    y = other.y;
    return *this;
  }
};

struct vec3 {
  union {
    float data[3];

    struct {
      float x, y, z;
    };

    struct {
      float r, g, b;
    };
  };

  SwizzleProxy2<vec3, 0, 0> xx;
  SwizzleProxy2<vec3, 0, 1> xy;
  SwizzleProxy2<vec3, 0, 2> xz;
  SwizzleProxy2<vec3, 1, 0> yx;
  SwizzleProxy2<vec3, 1, 1> yy;
  SwizzleProxy2<vec3, 1, 2> yz;
  SwizzleProxy2<vec3, 2, 0> zx;
  SwizzleProxy2<vec3, 2, 1> zy;
  SwizzleProxy2<vec3, 2, 2> zz;

  SwizzleProxy3<0, 0, 0> xxx;
  SwizzleProxy3<0, 0, 1> xxy;
  SwizzleProxy3<0, 0, 2> xxz;
  SwizzleProxy3<0, 1, 0> xyx;
  SwizzleProxy3<0, 1, 1> xyy;
  SwizzleProxy3<0, 1, 2> xyz;
  SwizzleProxy3<0, 2, 0> xzx;
  SwizzleProxy3<0, 2, 1> xzy;
  SwizzleProxy3<0, 2, 2> xzz;

  SwizzleProxy3<1, 0, 0> yxx;
  SwizzleProxy3<1, 0, 1> yxy;
  SwizzleProxy3<1, 0, 2> yxz;
  SwizzleProxy3<1, 1, 0> yyx;
  SwizzleProxy3<1, 1, 1> yyy;
  SwizzleProxy3<1, 1, 2> yyz;
  SwizzleProxy3<1, 2, 0> yzx;
  SwizzleProxy3<1, 2, 1> yzy;
  SwizzleProxy3<1, 2, 2> yzz;

  SwizzleProxy3<2, 0, 0> zxx;
  SwizzleProxy3<2, 0, 1> zxy;
  SwizzleProxy3<2, 0, 2> zxz;
  SwizzleProxy3<2, 1, 0> zyx;
  SwizzleProxy3<2, 1, 1> zyy;
  SwizzleProxy3<2, 1, 2> zyz;
  SwizzleProxy3<2, 2, 0> zzx;
  SwizzleProxy3<2, 2, 1> zzy;
  SwizzleProxy3<2, 2, 2> zzz;

  vec3()
      : x(0), y(0), z(0), xx(*this), xy(*this), xz(*this), yx(*this), yy(*this),
        yz(*this), zx(*this), zy(*this), zz(*this), xxx(*this), xxy(*this),
        xxz(*this), xyx(*this), xyy(*this), xyz(*this), xzx(*this), xzy(*this),
        xzz(*this), yxx(*this), yxy(*this), yxz(*this), yyx(*this), yyy(*this),
        yyz(*this), yzx(*this), yzy(*this), yzz(*this), zxx(*this), zxy(*this),
        zxz(*this), zyx(*this), zyy(*this), zyz(*this), zzx(*this), zzy(*this),
        zzz(*this) {}

  vec3(float x_val, float y_val, float z_val)
      : x(x_val), y(y_val), z(z_val), xx(*this), xy(*this), xz(*this),
        yx(*this), yy(*this), yz(*this), zx(*this), zy(*this), zz(*this),
        xxx(*this), xxy(*this), xxz(*this), xyx(*this), xyy(*this), xyz(*this),
        xzx(*this), xzy(*this), xzz(*this), yxx(*this), yxy(*this), yxz(*this),
        yyx(*this), yyy(*this), yyz(*this), yzx(*this), yzy(*this), yzz(*this),
        zxx(*this), zxy(*this), zxz(*this), zyx(*this), zyy(*this), zyz(*this),
        zzx(*this), zzy(*this), zzz(*this) {}

  vec3(const vec3 &other)
      : x(other.x), y(other.y), z(other.z), xx(*this), xy(*this), xz(*this),
        yx(*this), yy(*this), yz(*this), zx(*this), zy(*this), zz(*this),
        xxx(*this), xxy(*this), xxz(*this), xyx(*this), xyy(*this), xyz(*this),
        xzx(*this), xzy(*this), xzz(*this), yxx(*this), yxy(*this), yxz(*this),
        yyx(*this), yyy(*this), yyz(*this), yzx(*this), yzy(*this), yzz(*this),
        zxx(*this), zxy(*this), zxz(*this), zyx(*this), zyy(*this), zyz(*this),
        zzx(*this), zzy(*this), zzz(*this) {}

  vec3 &operator=(const vec3 &other) {
    if (this == &other) {
      return *this;
    }
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
  }
};

template <typename ParentVec, int I0, int I1>
inline SwizzleProxy2<ParentVec, I0, I1>::operator vec2() const {
  return vec2(v.data[I0], v.data[I1]);
}

template <typename ParentVec, int I0, int I1>
inline SwizzleProxy2<ParentVec, I0, I1> &
SwizzleProxy2<ParentVec, I0, I1>::operator=(const vec2 &other) {
  v.data[I0] = other.x;
  v.data[I1] = other.y;
  return *this;
}

template <int I0, int I1, int I2>
inline SwizzleProxy3<I0, I1, I2>::operator vec3() const {
  return vec3(v.data[I0], v.data[I1], v.data[I2]);
}

template <int I0, int I1, int I2>
inline SwizzleProxy3<I0, I1, I2> &
SwizzleProxy3<I0, I1, I2>::operator=(const vec3 &other) {
  v.data[I0] = other.x;
  v.data[I1] = other.y;
  v.data[I2] = other.z;
  return *this;
}

#endif // VEC3_HPP
