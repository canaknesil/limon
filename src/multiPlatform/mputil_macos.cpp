#ifdef __APPLE__

#include <mputil.h>

#include <mach-o/dyld.h>

bool getExecutablePath(char *buf, int len)
{
  uint32_t length = len;
  int ret = _NSGetExecutablePath(buf, &length);
  if (ret != 0)
    return false;
  else
    return true;
}

#endif
