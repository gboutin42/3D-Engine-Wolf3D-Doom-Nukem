NAME		=	doom-nukem

RED =		\033[1;31m
CYAN =		\033[1;36m
GREEN =		\033[1;32m
NO_COLOR =	\033[0m

INC_DIR		= 	./includes/
SRCS_DIR	= 	./srcs/
OBJ_DIR		=	./obj/
STR			=	$<
DWL 		=	brew

INC			= 	wolf3d.h \
				wolf3d_algorithm.h \
				wolf3d_basic.h \
				wolf3d_basic_list.h \
				wolf3d_camera.h \
				wolf3d_define.h \
				wolf3d_drawing.h \
				wolf3d_engine.h \
				wolf3d_engine_module.h \
				wolf3d_geometry.h \
				wolf3d_gui.h \
				wolf3d_includes.h \
				wolf3d_item.h \
				wolf3d_list.h \
				wolf3d_math.h \
				wolf3d_mesh.h \
				wolf3d_player.h \
				wolf3d_structure.h \
				wolf3d_system.h \
				wolf3d_vector.h \
				wolf3d_window.h

SRCS		=	main.c \
				algorithm/map_parser/load_item.c \
				algorithm/map_parser/load_map.c \
				algorithm/map_parser/load_player.c \
				algorithm/map_parser/map_parser.c \
				algorithm/save_map/save_map.c \
				algorithm/save_map/save_player.c \
				algorithm/check_map.c \
				algorithm/collision_detection.c \
				algorithm/obj_parser.c \
				algorithm/png_reader.c \
				algorithm/raycasting.c \
				basic_function/math/math.c \
				basic_function/math/math_geo.c \
				basic_function/math/math_geo_2.c \
				basic_function/math/math_triangle.c \
				basic_function/math/math_vector.c \
				basic_function/math/setting_float.c \
				basic_function/error_handler.c \
				basic_function/float_parsing.c \
				basic_function/ft_atof.c \
				basic_function/ft_ftoa.c \
				basic_function/ft_itoa.c \
				basic_function/ft_memalloc.c \
				basic_function/ft_memdel.c \
				basic_function/ft_strcat.c \
				basic_function/ft_strcpy.c \
				basic_function/ft_strdel.c \
				basic_function/generation.c \
				basic_function/get_next_line.c \
				basic_function/int_parsing.c \
				basic_function/is_number.c \
				basic_function/lst_handler.c \
				basic_function/memory_handler.c \
				basic_function/string_handler.c \
				basic_function/string_parsing.c \
				basic_function/string_print.c \
				basic_function/string_split.c \
				basic_function/string_tab.c \
				camera/adding_t_camera_list.c \
				camera/camera_recovery_in_list.c \
				camera/cleaning_t_camera_list.c \
				camera/clipping.c \
				camera/init_cam.c \
				camera/t_camera.c \
				camera/t_camera2.c \
				camera/t_camera3.c \
				camera/t_camera4.c \
				camera/t_camera5.c \
				camera/t_camera_handle.c \
				cpu_drawing/draw_rectangle_color_cpu.c \
				cpu_drawing/draw_rectangle_texture_cpu.c \
				cpu_drawing/draw_texture_cpu.c \
				cpu_drawing/draw_triangle_color_cpu.c \
				cpu_drawing/multithread_draw_color_cpu.c \
				cpu_drawing/multithread_draw_texture_cpu.c \
				cpu_drawing/pixel_handler.c \
				deployment/compression.c \
				engine/physic_engine/physic_engine.c \
				engine/physic_engine/physic_engine2.c \
				engine/physic_engine/physic_engine3.c \
				engine/sound_engine/load_sounds.c \
				engine/sound_engine/sound_engine.c \
				engine/user_engine/user_engine.c \
				engine/user_engine/user_engine_handle.c \
				engine/visual_engine/visual_engine.c \
				engine/visual_engine/visual_engine_next.c \
				engine/engine.c \
				engine/engine_camera.c \
				engine/engine_handle.c \
				engine/engine_mesh.c \
				geometry/t_line.c \
				geometry/t_rectangle.c \
				geometry/t_triangle.c \
				geometry/t_triangle_2.c \
				geometry/t_triangle_compose.c \
				geometry/t_triangle_list.c \
				geometry/t_triangle_list_2.c \
				geometry/t_triangle_math.c \
				gui/menus/control_menu.c \
				gui/menus/game_over.c \
				gui/menus/menu.c \
				gui/menus/pause.c \
				gui/menus/play_menu.c \
				gui/menus/save_menu.c \
				gui/menus/set_weapon_editing.c \
				gui/menus/settings_menu.c \
				gui/drawing_front.c \
				gui/free_t_gui.c \
				gui/free_t_texture.c \
				gui/load_text.c \
				gui/load_texture_map_editor.c \
				gui/minimap.c \
				gui/t_button.c \
				gui/t_gui.c \
				item/create_ammo_pack.c \
				item/t_item.c \
				item/t_item_jetpack.c \
				item/t_item_keys.c \
				item/t_item_list.c \
				item/t_item_list2.c \
				item/t_item_weapons.c \
				map_editor/map_editor.c \
				map_editor/move_mesh_editor.c \
				map_editor/move_mesh_editor2.c \
				map_editor/place_mesh.c \
				map_editor/place_mesh2.c \
				map_editor/print_map_editor.c \
				map_editor/print_map_editor2.c \
				map_editor/print_set_weapon.c \
				map_editor/select_mesh.c \
				map_editor/select_mesh2.c \
				map_editor/select_mesh3.c \
				matrice/creation_t_matrice.c \
				matrice/matrice_mult.c \
				matrice/rotation_matrice.c \
				mesh/draw_t_mesh.c \
				mesh/primitive_cube.c \
				mesh/primitive_plane.c \
				mesh/primitive_skybox.c \
				mesh/primitive_vertical_plane.c \
				mesh/t_door.c \
				mesh/t_mesh.c \
				mesh/t_mesh2.c \
				mesh/t_mesh_compute.c \
				mesh/t_mesh_lighting.c \
				mesh/t_mesh_list.c \
				mesh/t_mesh_list2.c \
				mesh/t_mesh_move.c \
				mesh/t_mesh_move2.c \
				mesh/t_mesh_set.c \
				opengl/draw_opengl.c \
				opengl/shader_handler.c \
				player/player_action.c \
				player/shoot_weapon.c \
				player/t_player.c \
				player/t_player2.c \
				player/t_weapons.c \
				playing/playing_functions.c \
				rasterizer/t_rasterizer.c \
				structure/void_list/void_list.c \
				structure/void_list/void_list_init.c \
				structure/t_face.c \
				structure/t_face_list.c \
				structure/t_texture.c \
				structure/t_uv.c \
				structure/t_uv_list.c \
				system/t_keyboard.c \
				system/t_mouse.c \
				t_color/t_color.c \
				t_color/t_color_list.c \
				t_enemy/t_enemy.c \
				t_enemy/t_enemy_boss.c \
				vector2/t_vector2.c \
				vector2/t_vector2_int.c \
				vector4/t_vector4.c \
				vector4/t_vector4_list.c \
				vector4/t_vector4_list2.c \
				vector4/t_vector4_list3.c \
				vector4/t_vector4_math.c \
				window/clear_buffers.c \
				window/convert.c \
				window/fps_handler.c \
				window/t_view_port.c \
				window/window_handler.c \
				window/window_handler2.c

##Transform and place every .o from SRC
INCFILES = $(addprefix $(INC_DIR), $(INC))
SRCFILES = $(addprefix $(SRCS_DIR), $(SRCS))
OBJFILES = $(addprefix $(OBJ_DIR), $(OBJ))
DIR_PREP = $(shell find $(SRCS_DIR) -type d -exec echo {} \; | sed 's~$(SRCS_DIR)~$(OBJ_DIR)~g')

OBJ = $(SRCS:.c=.o)
##List of libraries to download and install using the function defined in DWL
LIB_DWN =	sdl2 sdl2_image sdl2_mixer sdl2_ttf png
##List of libraries to link while compiling
LIB =		SDL2 SDL2_image SDL2_mixer SDL2_ttf png

##
##		COMPILER FLAGS
##

##Basics flags for 42
CFLAGS=		-std=c89 -O3 -flto -Wno-deprecated-declarations -Wall -Wextra -Werror

##Create the flags to includes every .h needed by this program
IFLAGS =	$(foreach dir, $(INC_DIR), -I$(dir)) $(foreach dir, $(shell find ~/.brew/include -type d), -I$(dir))

##Create the flags to link every libraries needed by this program (-L and -l)
LFLAGS = 	-L ~/.brew/lib $(foreach lib, $(LIB), -l$(lib) ) -framework OpenGL

##Define the compiler to use
CC=			gcc

all:			$(NAME)

install:
				make libs
				make $(NAME)

libs:
				$(foreach lib, $(LIB_DWN), $(DWL) install $(lib); )

$(NAME):		$(OBJFILES) $(INCFILES) Makefile
				@$(CC) $(CFLAGS) $(IFLAGS) -o $@ $(OBJFILES) $(LFLAGS)
				@printf "$(CYAN)Compiling:\t$(GREEN)%50s$(RED)\tDONE$(NO_COLOR)\n" $(NAME)

$(OBJ_DIR)%.o : $(SRCS_DIR)%.c $(INCFILES)
				@mkdir -p $(DIR_PREP)
				@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $< -I $(INC_DIR)
				@printf "$(CYAN)Compiling:\t$(GREEN)%50s$(RED)\tDONE$(NO_COLOR)\r" $(STR)

clean:
				@rm -rf $(OBJ_DIR)
				@echo "$(RED)clean$(NO_COLOR)"

fclean:			clean
				@rm -f $(NAME)
				@echo "$(RED)fclean$(NO_COLOR)"

re:				fclean all

.PHONY: all clean fclean re
