#pragma once

/**
 * @brief Inicializa todo el sistema de sensores
 * 
 * @param gid ID de grupo de todos los sensores
 */
void setupSensors(String gid);

/**
 * @brief Activa un ciclo de gestión de los sensores
 */
void handleSensors();