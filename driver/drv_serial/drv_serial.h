#ifndef AVSOFT_DRV_UART_H
#define AVSOFT_DRV_UART_H

#include <cstdint>
#include <string>
#include <termios.h>

#define ERR_OPEN    -1
#define ERR_SETBAUD -2
#define ERR_GETBAUD -3
#define ERR_IOFLUSH -4

#define SERIAL_SEND_FAILED      std::cerr << "SEND ...    [FAILED]" << std::endl;
#define SERIAL_RECEIVE_FAILED   std::cerr << "RECEIVE ... [FAILED]" << std::endl;

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
	void flushio();

private:

	const char *mp_devPath;
	int32_t mp_fileDesc;
	int32_t mp_baudRate;
	serialio_t mp_oldio;
	serialio_t mp_newio;

	int32_t getBaudout();
	int32_t getBaudin();
	bool setBaud();

	void errorHandler(int32_t _errCode);
};

#endif // AVSOFT_DRV_UART_H
