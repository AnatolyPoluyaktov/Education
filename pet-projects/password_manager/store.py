import os
import json

with open("path", "r") as fd:
    path = fd.read()


class Borg:
    _shared_state = {}

    def __init__(self):
        self.__dict__ = self._shared_state


class Storage(Borg):
    def __init__(self):
        Borg.__init__(self)
        self.d = {}

    def read(self):
        if os.path.isfile(path):
            if os.stat(path).st_size == 0:
                self.d = {}
            else:
                with open(path, "r") as fd:
                    self.d = json.load(fd)
        else:
            with open(path, "w") as fd:
                self.d = {}

    def write(self):
        with open(path, "w") as fd:
            json.dump(self.d, fd)

    def put(self, domain, login, password):
        if domain in self.d:
            self.d[domain].append((login, password))
        else:
            self.d[domain] = []
            self.d[domain].append((login, password))

    def get_data(self, domain):
        return self.d[domain]


if __name__ == "__main__":
    data = Storage()
    data.read()


kek = Storage()
