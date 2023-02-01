class Solution
{
public:
    double rad, x, y;
    Solution(double radius, double x_center, double y_center)
    {
        rad = radius;
        x = x_center;
        y = y_center;
    }

    vector<double> randPoint()
    {
        double ang = (double)rand() / RAND_MAX * 2 * M_PI,
               newrad = sqrt((double)rand() / RAND_MAX) * rad,
               x_add = cos(ang) * newrad,
               y_add = sin(ang) * newrad;
        return vector<double>{x + x_add, y + y_add};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */