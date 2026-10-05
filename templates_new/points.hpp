template<typename T>
struct Point {
  T x, y;
  Point(T x = 0, T y = 0) : x(x), y(y) {}
  friend bool operator==(Point a, Point b) { return a.x == b.x && a.y == b.y; }
  Point operator+(Point o) const { return Point(x + o.x, y + o.y); }
  Point operator-(Point o) const { return Point(x - o.x, y - o.y); }
  Point operator*(T o) const { return Point(x * o, y * o); }
  Point operator/(T o) const { return Point(x / o, y / o); }
  T dist2() const { return x * x + y * y; }
  double dist() const { return sqrt(dist2()); }
  double angle() const { return atan2(y, x); }
  Point unit() const { return *this / dist(); }
  Point perp() const { return Point(-y, x); }
  Point normal() const { return perp().unit(); }
  Point rotate(double a) const {
    return Point(
      x * cos(a) - y * sin(a),
      x * sin(a) + y * cos(a)
    );
  }    
  friend T dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
  friend T cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
  friend bool ccw(Point a, Point b, Point c) { return cross(b - a, c - b) > 0; }
  friend bool collinear(Point a, Point b, Point c) { return cross(b - a, c - b) == 0; }
  friend bool cw(Point a, Point b, Point c) { return cross(b - a, c - b) < 0; }
  friend ostream& operator<<(ostream& out, Point a) {
    out << "(" << a.x << ", " << a.y << ")";
    return out;
  }
  friend istream& operator>>(istream& in, Point &a) {
    in >> a.x >> a.y;
    return in;
  }
};

/*
 Calculate signed distance from point p to line between a, b. Can be used to test if two points are on different sides.
*/
template<typename P>
double line_dist(P a, P b, P p) {
  return (double) cross(b - a, p - a) / (b - a).dist();
}

// Project or reflect a point with respect to a line. 
template<typename P>
P project(P a, P b, P p) {
  return a + (b - a) * (double) dot(b - a, p - a) / (b - a).dist2();
}
template<typename P>
P reflect(P a, P b, P p) {
  auto ap = p - a;
  auto ah = project(a, b, p) - a;
  return ah * 2 - ap + a;
}

// Shortest distance from point $p$ to line segment between a, b.
template<typename P>
double seg_dist(P a, P b, P p) {
  auto t = (double) dot(b - a, p - a) / (b - a).dist2();
  double ans = fmin((p - a).dist(), (p - b).dist());
  if (t >= 0 && t <= 1.0) {
    ans = fmin(ans, fabs(line_dist(a, b, p)));
  }
  return ans;
}

// Check if a point lies on a given segment.
template<typename P>
bool on_seg(P a, P b, P p) {
  return collinear(a, b, p) && dot(p - a, b - p) >= 0;
}
