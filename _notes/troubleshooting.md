

## Pass matrix to shader
```
glUniformMatrix4fv(loc, 1, GL_TRUE, glm::value_ptr(matrix));
```

transpose : determain column major（GL_FALSE）or row major (GL_TRUE）

To row major matrix, the order of matrix operation should from left to right, 
```
  gl_Position = pos * model * view * projection;
```