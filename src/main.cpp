#include <getopt.h>
#include <nos/fprint.h>
#include <nos/io/serial_port.h>
#include <string>

const char *VERSION = "0.1.0";
std::string filename = {};

static struct option long_options[] = {{"help", no_argument, 0, 'h'},
                                       {"version", no_argument, 0, 'v'},
                                       {0, 0, 0, 0}};

void parse_args(int argc, char **argv)
{
    int c;
    while (1)
    {
        int option_index = 0;
        c = getopt_long(argc, argv, "hvf:", long_options, &option_index);
        if (c == -1)
            break;
        switch (c)
        {
        case 'h':
            nos::fprint("Usage: {} FILE [options]\n"
                        "Options:\n"
                        "  -h, --help\t\tShow this help message\n"
                        "  -v, --version\t\tShow version\n",
                        argv[0]);
            exit(0);

        case 'v':
            nos::fprintln("Version: {}", VERSION);
            break;

        case '?':
            break;
        }
    }

    if (argc - optind == 0)
    {
        nos::fprint("Usage: {} FILE [options]\n"
                    "Try '{} --help' for more information.\n",
                    argv[0],
                    argv[0]);
        exit(1);
    }

    if (argc - optind > 1)
    {
        nos::fprint("Usage: {} FILE [options]\n"
                    "Try '{} --help' for more information.\n",
                    argv[0],
                    argv[0]);
        exit(1);
    }

    filename = argv[optind];
}

int main(int argc, char **argv)
{
    parse_args(argc, argv);

    if (filename.empty())
    {
        nos::println("No file specified");
        return 1;
    }

    nos::serial_port port(filename.c_str());
    if (!port.good())
    {
        nos::println("Failed to open port");
        return 1;
    }

    nos::println_to(port, "STARTTEST");

    while (1)
    {
        char c;
        if (port.read(&c, 1) == 1)
        {
            nos::write(&c, 1);
        }
    }
}