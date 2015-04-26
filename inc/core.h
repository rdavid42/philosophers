#ifndef CORE_H
# define CORE_H

# ifdef linux
#  include <GL/glu.h>
#  include <GL/gl.h>
#  include <GL/glut.h>
#  include <SDL2/SDL.h>
# endif

# ifdef __APPLE__
#  include <openGL/glu.h>
#  include <openGL/gl.h>
#  include <GLUT/glut.h>
#  include <SDL.h>
# endif

# ifdef __WIN32__
#  include <GL/gl.h>
#  include <GL/glut.h>
#  include <windows.h>
#  include <SDL.h>
# endif

# include <pthread.h>
# include "constants.h"

typedef struct			s_stick
{
	int					state;
	pthread_mutex_t		mutex;
}						t_stick;

typedef struct			s_philosopher
{
	int					life;
	struct s_core		*c;
	int					state;
	int					left_locked;
	int					right_locked;
	int					i;
	int					stop;
	pthread_t			thread;
}						t_philosopher;

typedef struct			s_core
{
	int					width;
	int					height;
	SDL_Window			*window;
	SDL_GLContext		*context;
	t_stick				s[PN];
	t_philosopher		p[PN];
}						t_core;

char					*itoa(int n);
int						init_core(t_core *c);
int						init_sticks(t_core *c);
int						init_philosophers(t_core *c);
int						start_philosophers(t_core *c);
int						loop(t_core *c);
void					gl_enable_2d(int cam_x, int cam_y);
void					gl_disable_2d(void);
void					on_keyboard(SDL_KeyboardEvent const *e);
void					update(t_core *c);
void					render(t_core *c);
int						sdl_error(int code);
int						release_sticks(t_core *c);
int						slen(char *str);

#endif