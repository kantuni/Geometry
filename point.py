""" Created by Henrikh Kantuni on 11/23/16 """


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __repr__(self):
        return '({0}, {1})'.format(self.x, self.y)
