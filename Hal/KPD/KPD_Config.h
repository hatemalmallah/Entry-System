/*
 * KPD_Config.h
 *
 *  Created on: Sep 10, 2026
 *      Author: hatem
 */

#ifndef HAL_KPD_KPD_CONFIG_H_
#define HAL_KPD_KPD_CONFIG_H_

#define KPD_ColNo   4
#define KPD_RowNo   4

//*********************************//

#define KPD_R0Pin      DIO_Pin4
#define KPD_R0Group    DIO_GroupA

#define KPD_R1Pin      DIO_Pin5
#define KPD_R1Group    DIO_GroupA

#define KPD_R2Pin      DIO_Pin6
#define KPD_R2Group    DIO_GroupA

#define KPD_R3Pin      DIO_Pin7
#define KPD_R3Group    DIO_GroupA


//*********************************//
#define KPD_C0Pin      DIO_Pin3
#define KPD_C0Group    DIO_GroupA

#define KPD_C1Pin      DIO_Pin2
#define KPD_C1Group    DIO_GroupA

#define KPD_C2Pin      DIO_Pin1
#define KPD_C2Group    DIO_GroupA

#define KPD_C3Pin      DIO_Pin0
#define KPD_C3Group    DIO_GroupA


//*********************************//
#define KPD_RGroupConfigured  {KPD_R0Group,KPD_R1Group,KPD_R2Group,KPD_R3Group}

#define KPD_RPinConfigured	   {KPD_R0Pin,KPD_R1Pin,KPD_R2Pin,KPD_R3Pin}
//*********************************//
#define KPD_CGroupConfigured  {KPD_C0Group,KPD_C1Group,KPD_C2Group,KPD_C3Group}

#define KPD_CPinConfigured	   {KPD_C0Pin,KPD_C1Pin,KPD_C2Pin,KPD_C3Pin}

//*********************************//


#define KPD_ValuesConfigured  { {'1','2','3','A'},\
								{'4','5','6','B'},\
								{'7','8','9','C'},\
                                {'*','0','#','E'}}






#endif /* HAL_KPD_KPD_CONFIG_H_ */
