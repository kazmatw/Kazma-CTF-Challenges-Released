#!/usr/bin/env python3
import os
import random
import sys
import tempfile

import jinja2


def generate(argv):
    if len(argv) != 3:
        print("Usage: ./generate.py [seed] [output_file]")
        sys.exit()

    seed = argv[1]
    output_file = argv[2]
    random.seed(seed)
    userdef_charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    userdef0 = "".join([random.choice(userdef_charset) for _ in range(8)])
    userdef1 = "".join([random.choice(userdef_charset) for _ in range(8)])
    userdef2 = "".join([random.choice(userdef_charset) for _ in range(8)])
    userdef3 = "".join([random.choice(userdef_charset) for _ in range(8)])
    padding = random.randint(0, 2**26)

    template = open(
        os.path.join(
            os.path.dirname(os.path.realpath(__file__)),
            "rage.c.jinja",
        ),
        "r",
    ).read()
    t = jinja2.Template(template)
    c_code = t.render(
        description="",
        padding=padding,
        userdef0=userdef0,
        userdef1=userdef1,
        userdef2=userdef2,
        userdef3=userdef3,
    )

    with tempfile.NamedTemporaryFile(delete=False, suffix=".c", mode="w") as temp:
        temp.write(c_code)
        temp.seek(0)
        os.system("gcc -fno-pie -no-pie -m32 -o " + output_file + " " + temp.name)


if __name__ == "__main__":
    generate(sys.argv)

# ./generate.py 1109 rage
