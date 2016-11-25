""" Created by Henrikh Kantuni on 11/23/16 """

from point import Point


class Line:
    def __init__(self, m, b, a):
        """
        Create a line from a slope, a y-intercept, and an x-intercept

        :param m: slope
        :param b: y-intercept
        :param a: x-intercept
        """
        self.m = m
        self.b = b
        self.a = a

    def __repr__(self):
        if self.m is None:
            return 'y = 0, x = {0}'.format(self.a)
        elif self.m == 0:
            return 'y = {0}'.format(self.b)
        else:
            return 'y = {0}x + {1}'.format(self.m, self.b)

    @classmethod
    def from_two_points(cls, p, q):
        """
        Get a line equation from 2 points

        :param p: {Point}
        :param q: {Point}
        :return: {Line}
        """
        m = None if p.x == q.x else (p.y - q.y) / (p.x - q.x)
        b = 0 if m is None else p.y - m * p.x
        a = p.x if m is None else (0 if m == 0 else -b / m)

        return cls(m, b, a)

    @classmethod
    def from_point_and_slope(cls, p, m):
        """
        Get a line equation from a point and a slope

        :param p: {Point}
        :param m: slope
        :return: {Line}
        """
        b = 0 if m is None else p.y - m * p.x
        a = p.x if m is None else (0 if m == 0 else -b / m)

        return cls(m, b, a)

    def is_parallel(self, other):
        """
        Check if 2 lines are parallel

        :param other: {Line}
        :return: {bool}
        """
        return self.m == other.m  # assuming they are not the same

    def point_of_intersection(self, other):
        """
        Return the point of intersection of two lines
        or None if they are parallel

        :param other: {Line}
        :return: {Point} or {None}
        """
        if self.is_parallel(other):
            return None

        if self.m is not None and other.m is not None:
            x = (other.b - self.b) / (self.m - other.m)
            y = self.m * x + self.b
        elif self.m is None:
            x = self.a
            y = other.m * x + other.b
        else:
            x = other.a
            y = self.m * x + self.b

        return Point(x, y)

    def perpendicular(self, p):
        """
        Drop a perpendicular from a point to a line

        :param p: {Point}
        :return: {Line} perpendicular or {None} if the point is on the line
        """
        if self.m is not None:
            # if the point is on the line
            if p.y == self.m * p.x + self.b:
                return None

            if self.m == 0:
                # vertical line
                perpendicular = Line(None, 0, p.x)
            else:
                # line with a "negative reciprocal" slope
                perpendicular = self.from_point_and_slope(p, -1 / self.m)
        else:
            # if the point is on the line
            if p.x == self.a:
                return None

            # horizontal line
            perpendicular = Line(0, p.y, 0)

        return perpendicular
