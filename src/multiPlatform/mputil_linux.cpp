#ifdef __linux__

#include <mputil.h>

#include <unistd.h>

bool getExecutablePath(char *buf, int len)
{
  ssize_t ret = readlink("/proc/self/exe", buf, len);
  if (ret == -1)
    return false;
  else
    return true;
}

#endif
