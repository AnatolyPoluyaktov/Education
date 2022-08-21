from django.forms import ModelForm

from .models import File


class FileUploadForm(ModelForm):
    class Meta:
        model = File
        fields = ["file_name", "file_path"]

