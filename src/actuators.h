#pragma once

/**
 * @brief Inicializa todo el sistema de actuadores
 * 
 * @param gid ID de grupo de todos los actuadores
 */
void setupActuators(const String gid);

/**
 * @brief Activa un ciclo de gestión de los actuadores
 */
void handleActuators();