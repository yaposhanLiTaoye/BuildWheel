#include "BasicFunc.h"

bool CopyFileLTY(char *srcFile, char *dstFile)
{
    bool retValue = false;

    FILE *srcFp = fopen(srcFile, "rb");
    if (NULL == srcFp) {
        L_ERROR("open file %s failed", srcFile);
        goto FAIL_HANDLE_0;
    }

    FILE *dstFp = fopen(dstFile, "wb");
    if (NULL == dstFp) {
        L_ERROR("open file %s failed", dstFile);
        goto FAIL_HANDLE_1;
    }

    #define BytesOneTime 1024
    unsigned char buffer[BytesOneTime] = {0};
    size_t realReadBytes = 0;
    size_t realWriteBytes = 0;

    while ((realReadBytes = fread(buffer, 1, BytesOneTime, srcFp)) > 0) {
        realWriteBytes = fwrite(buffer, 1, realReadBytes, dstFp);
        if (realWriteBytes != realReadBytes) {
            L_ERROR("write data failed");
            fclose(srcFp);
            fclose(dstFp);
            // we must call remove after fclose the corresponding file descriptor
            if (remove(dstFile) != 0) {
                L_ERROR("delete dst file %s failed, error: %s", dstFile, strerror(errno));
            } else {
                L_INFO("delete dst file %s success", dstFile);
            }
            return false;
        }
    }
    #undef BytesOneTime

    L_INFO("copy file %s to %s success", srcFile, dstFile);
    retValue = true;

FAIL_HANDLE_2:
    fclose(dstFp);
FAIL_HANDLE_1:
    fclose(srcFp);
FAIL_HANDLE_0:
    return retValue;
}
