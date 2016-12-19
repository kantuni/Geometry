""" Created by Henrikh Kantuni on 11/23/16 """


class Circle:
    def __init__(self, center, r):
        self.center = center
        self.r = r

    def __repr__(self):
        return '(x-{0})^2 + (y-{1})^2 = {2}^2'.format(self.center.x, self.center.y, self.r)

    def point_in_circle(self, point):
        """
        Check if a point is inside a circle

        :param point: {Point}
        :return: {bool}
        """
        return True if (point.x - self.center.x) ** 2 + (point.y - self.center.y) ** 2 < self.r ** 2 else False

    def line_intersects_circle(self, line):
        """
        Check if a line intersects a circle

        :param line: {Line}
        :return: {bool}
        """
        perpendicular = line.perpendicular(self.center)
        # line through a circle center
        if perpendicular is None:
            return True
        else:
            intersection = line.point_of_intersection(perpendicular)
            if intersection and self.point_in_circle(intersection):
                return True
            return False
