/*******************************************************************************
 *	@brief	延迟函数 xus=1时，大约延迟25us
 *	@param	无符号整型
 *	@retval	无
*******************************************************************************/
void Delay_25us(unsigned int xus)
{
	while(xus--);
}