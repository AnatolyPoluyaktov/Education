from django.db import models

class File(models.Model):
    file_name = models.CharField(max_length=255)
    file_path = models.FileField(upload_to="media/")
    uploaded_at = models.DateTimeField(auto_now_add=True)

