#ifndef DRV_SERIAL
#define DRV_SERIAL

#include <cstdint>
#include <string>
#include <termios.h>

typedef struct termios serialio_t;

class drv_serial
{
public:
	drv_serial();
	~drv_serial();

	bool init(const char *_devPath, int32_t _baudRate);
	bool access();
	bool config();
	bool vanish();

	bool send(uint8_t _data[], int32_t _len);
	bool receive(uint8_t _data[], int32_t _len);
	bool flushio();

private:

	const char *mp_devPath;
	int32_t mp_fileDesc;
	int32_t mp_baudRate;
	serialio_t mp_oldio;
	serialio_t mp_newio;

	int32_t getBaudout();
	int32_t getBaudin();
	bool setBaud();
};

#endif // DRV_SERIAL
