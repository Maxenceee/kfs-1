MANDATORY_DIR   =   sources
OBJ_DIR         =   .objs
ISO_DIR         =   iso_root

SRCS            =   $(shell find $(MANDATORY_DIR) -name "*.c")
SRCS_ASM        =   $(shell find $(MANDATORY_DIR) -name "*.asm")

OBJS            =   $(patsubst $(MANDATORY_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))
OBJS_ASM        =   $(patsubst $(MANDATORY_DIR)%.asm, $(OBJ_DIR)%.o, $(SRCS_ASM))

NAME            =   mykernel.bin
ISO_NAME        =   myos.iso

CC              =   gcc
ASM             =   nasm
RM              =   rm -rf

CFLAGS          =   -m32 \
                    -fno-builtin \
                    -fno-exceptions \
                    -fno-stack-protector \
                    -fno-rtti \
                    -nostdlib \
                    -nodefaultlibs \
                    -ffreestanding \
                    -fno-pie \
                    -Wall -Wextra -Werror

ASMFLAGS        =   -f elf32
LDFLAGS         =   -m32 -T linker.ld -nostdlib -nodefaultlibs -no-pie

GREEN           =   \033[1;32m
YELLOW          =   \033[1;33m
RED             =   \033[1;31m
DEFAULT         =   \033[0m

$(OBJ_DIR)/%.o: $(MANDATORY_DIR)/%.c
	@mkdir -p $(@D)
	@echo "$(YELLOW)Compiling C [$<]$(DEFAULT)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(MANDATORY_DIR)/%.asm
	@mkdir -p $(@D)
	@echo "$(YELLOW)Compiling ASM [$<]$(DEFAULT)"
	@$(ASM) $(ASMFLAGS) $< -o $@

all: $(ISO_NAME)

$(NAME): $(OBJS) $(OBJS_ASM)
	@echo "$(YELLOW)Linking $(NAME)...$(DEFAULT)"
	@$(CC) $(LDFLAGS) $^ -o $(NAME)

$(ISO_NAME): $(NAME)
	@echo "$(YELLOW)Creating ISO...$(DEFAULT)"
	@mkdir -p $(ISO_DIR)/boot/grub
	@cp $(NAME) $(ISO_DIR)/boot/
	@echo 'set timeout=0' > $(ISO_DIR)/boot/grub/grub.cfg
	@echo 'set default=0' >> $(ISO_DIR)/boot/grub/grub.cfg
	@echo 'menuentry "My OS" {' >> $(ISO_DIR)/boot/grub/grub.cfg
	@echo '  multiboot /boot/$(NAME)' >> $(ISO_DIR)/boot/grub/grub.cfg
	@echo '  boot' >> $(ISO_DIR)/boot/grub/grub.cfg
	@echo '}' >> $(ISO_DIR)/boot/grub/grub.cfg
	@grub-mkrescue -o $(ISO_NAME) $(ISO_DIR)
	@echo "$(GREEN)$(ISO_NAME) is ready!$(DEFAULT)"

clean:
	@echo "$(RED)Cleaning objects$(DEFAULT)"
	@$(RM) $(OBJ_DIR) $(ISO_DIR)

fclean: clean
	@echo "$(RED)Cleaning $(NAME)$(DEFAULT)"
	@$(RM) $(NAME) $(ISO_NAME)

re: fclean all

.PHONY: all clean fclean re